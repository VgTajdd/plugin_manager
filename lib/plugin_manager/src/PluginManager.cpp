// ========================================================================= //
// Copyright (c) 2021 Agustin Jesus Durand Diaz.                             //
// This code is licensed under the MIT License.                              //
// PluginManager.cpp                                                         //
// ========================================================================= //

#include <iostream>
#include "PluginManager.h"
#include <common/IPlugin.h>
#include <common/PluginDefines.h>

#ifdef _WIN32
#include <windows.h>
#define LOAD_HANDLE(filename_str) LoadLibraryA((filename_str + ".dll").c_str())
#define UNLOAD_HANDLE(x) FreeLibrary((HMODULE)(x))
#define GET_FUNCTION_ADDRESS GetProcAddress
#else
#include <dlfcn.h>
#define LOAD_HANDLE(filename_str) dlopen(("./lib" + filename_str + ".so").c_str(), RTLD_LAZY);
#define UNLOAD_HANDLE dlclose
#define GET_FUNCTION_ADDRESS dlsym
#endif

typedef IPlugin* ( *ReturnIPluginFunction )( );

// This time we will use an exported plugin-function called 'getInstance'
// which will return the memory address of the static instance in the shared library.
// When the shared library is unloaded this static instance variable gets destroyed.
// If we were using a concrete plugin which will require much more space in memory
// the static strategy may not be the best solution and a 'createInstance' and
// 'destroyInstance' would be required.
IPlugin* PluginManager::loadPlugin( const char* filename )
{
	// Load handle (so/dll).
	auto handle = LOAD_HANDLE( std::string( filename ) );
	if ( !handle )
	{
		std::cout << "Plugin handle \"" << filename << "\" was not found." << std::endl;
		return nullptr;
	}

	// Get address of the 'getInstance' function.
	auto GET_INSTANCE = (ReturnIPluginFunction) GET_FUNCTION_ADDRESS( handle, GET_INSTANCE_STR );
	if ( !GET_INSTANCE )
	{
		std::cout << "Failed to get the address of the function \"" << GET_INSTANCE_STR << "\"." << std::endl;
		UNLOAD_HANDLE( handle );
		return nullptr;
	}

	// Create instance of the loaded plugin.
	auto instance = GET_INSTANCE();
	if ( instance == nullptr )
	{
		std::cout << "Function \"" << GET_INSTANCE_STR << "\" was found but it returns nullptr." << std::endl;
		UNLOAD_HANDLE( handle );
		return nullptr;
	}
	m_handles[filename] = handle;
	m_plugins[filename] = instance;
	return instance;
}

bool PluginManager::unloadPlugin( const char* filename )
{
	if ( m_handles.find( filename ) == m_handles.end() )
	{
		std::cout << "Plugin instance \"" << filename << "\" was not found." << std::endl;
		return false;
	}
	UNLOAD_HANDLE( m_handles.at( filename ) );
	m_handles.erase( filename );
	m_plugins.erase( filename );
	return true;
}

IPlugin* PluginManager::getPlugin( const char* filename )
{
	if ( m_plugins.find( filename ) == m_plugins.end() )
	{
		std::cout << "Plugin instance \"" << filename << "\" was not found." << std::endl;
		return nullptr;
	}
	return m_plugins.at( filename );
}

IPluginManager* IPluginManager::Get()
{
	static PluginManager instance;
	return &instance;
}

PluginManager::~PluginManager()
{
	// The creation and destruction of the concrete plugin MUST be done inside it's shared lib.
	m_plugins.clear();
	for ( auto [filename, handle] : m_handles )
	{
		UNLOAD_HANDLE( m_handles.at( filename ) );
	}
	m_handles.clear();
}
