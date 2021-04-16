#pragma once

#include "../public/IPluginManager.h"
#include <unordered_map>
#ifdef _WIN32
#include <windows.h>
#else
#include <dlfcn.h>
#endif

class PluginManager : public IPluginManager
{
public:
	~PluginManager();
	bool loadPlugin( const char* filename );
	bool unloadPlugin( const char* filename );
	class IPlugin* getPlugin( const char* filename );
private:
	std::unordered_map<std::string, IPlugin*> m_plugins;
	std::unordered_map<std::string, HINSTANCE> m_handles;
};