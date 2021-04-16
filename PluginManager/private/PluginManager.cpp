#include "PluginManager.h"
#include <Common/IPlugin.h>
#include <iostream>

// This time we will only use an exported plugin method called 'getInstance'
// which will return de memory address of the static instace in the dll.
// When the dll is unloaded this static instance variable gets destroyed.
//
// If we were using a concrete plugin wich will require much more space in memory
// the static strategy may not be the best solution and a 'createInstance' and
// 'destroyInstance' would be required.
bool PluginManager::loadPlugin( const char* filename )
{
	std::string filename_str = filename;
#ifdef _WIN32
	auto handle = LoadLibraryA( filename_str.c_str() );
	if ( !handle )
	{
		std::cout << "Failed to load plugin: " << filename << std::endl;
		return false;
	}
	auto getInstance = ( IPlugin*(*)())GetProcAddress( handle, "getInstance" );
	if ( !getInstance )
	{
		FreeLibrary( handle );
		std::cout << "Failed to get adress to load function \"getInstance\"" << std::endl;
		return false;
	}
#else
	auto handle = dlopen( ( "lib" + filename_str + ".so" ).c_str(), RTLD_LAZY );
	if ( !handle )
	{
		std::cout << "Failed to load plugin: " << dlerror() << std::endl;
		return false;
	}
	auto getInstance = ( IPlugin * ( * )( ) )dlsym( handle, "getInstance" );
	if ( !load )
	{
		dlclose( handle );
		std::cout << "Failed to get address of load function: " << dlerror() << std::endl;
		return false;
	}
#endif
	auto object = getInstance();
	if ( object == nullptr )
	{
		return false;
	}
	m_handles[filename] = handle;
	m_plugins[filename] = object;
#ifndef _WIN32
	//auto name = (char* (*)())dlsym(handle, "name");
	//auto version = (char* (*)())dlsym(handle, "version");
#endif
	return true;
}

bool PluginManager::unloadPlugin( const char* filename )
{
	if ( m_handles.find( filename ) == m_handles.end() )
	{
		std::cout << "ERROR: Pluging " << filename << " is not loaded." << std::endl;
		return false;
	}
	FreeLibrary( m_handles.at( filename ) );
	m_handles.erase( filename );
	m_plugins.erase( filename );
	return true;
}

IPlugin* PluginManager::getPlugin( const char* filename )
{
	if ( m_plugins.find( filename ) == m_plugins.end() )
	{
		std::cout << "ERROR: Pluging " << filename << " is not loaded." << std::endl;
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
	// The creation and destruction of the concrete plugin should be done inside it's dll.
	m_plugins.clear();

	for ( auto [filename, handle] : m_handles )
	{
		FreeLibrary( handle );
	}
	m_handles.clear();
}