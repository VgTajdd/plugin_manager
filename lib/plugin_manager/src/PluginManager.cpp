#include <iostream>
#include "PluginManager.h"
#include <common/IPlugin.h>

#ifdef _WIN32
#include <windows.h>
#define UNLOAD_HANDLE(x) FreeLibrary((HMODULE)(x))
#else
#include <dlfcn.h>
#define UNLOAD_HANDLE dlclose
#endif

// This time we will only use an exported plugin-function called 'getInstance'
// which will return de memory address of the static instance in the shared library.
// When the shared library is unloaded this static instance variable gets destroyed.
//
// If we were using a concrete plugin wich will require much more space in memory
// the static strategy may not be the best solution and a 'createInstance' and
// 'destroyInstance' would be required.
bool PluginManager::loadPlugin( const char* filename )
{
	std::string filename_str = filename;
#ifdef _WIN32
	filename_str += ".dll";
	auto handle = LoadLibraryA( filename_str.c_str() );
	if ( !handle )
	{
		std::cout << "Failed to load plugin: " << filename_str.c_str() << std::endl;
		return false;
	}
	auto getInstance = ( IPlugin*(*)())GetProcAddress( handle, "getInstance" );
	if ( !getInstance )
	{
		UNLOAD_HANDLE( handle );
		std::cout << "Failed to get adress to load function \"getInstance\"" << std::endl;
		return false;
	}
#else
	auto handle = dlopen( ( "./lib" + filename_str + ".so" ).c_str(), RTLD_LAZY );
	if ( !handle )
	{
		std::cout << "Failed to load plugin: " << dlerror() << std::endl;
		return false;
	}
	auto getInstance = ( IPlugin* (*)() )dlsym( handle, "getInstance" );
	if ( !getInstance)
	{
		UNLOAD_HANDLE( handle );
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
	return true;
}

bool PluginManager::unloadPlugin( const char* filename )
{
	if ( m_handles.find( filename ) == m_handles.end() )
	{
		std::cout << "ERROR: Pluging " << filename << " is not loaded." << std::endl;
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
	// The creation and destruction of the concrete plugin MUST be done inside it's shared lib.
	m_plugins.clear();
	for ( auto [filename, handle] : m_handles )
	{
		UNLOAD_HANDLE( m_handles.at( filename ) );
	}
	m_handles.clear();
}