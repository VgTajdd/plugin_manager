// ========================================================================= //
// Copyright (c) 2021 Agustin Jesus Durand Diaz.                             //
// This code is licensed under the MIT License.                              //
// PluginManager.h                                                           //
// ========================================================================= //

#pragma once

#include "plugin_manager/IPluginManager.h"
#include <unordered_map>

class PluginManager : public IPluginManager
{
public:
	~PluginManager();
	bool loadPlugin( const char* filename );
	bool unloadPlugin( const char* filename );
	class IPlugin* getPlugin( const char* filename );
private:
	std::unordered_map<std::string, IPlugin*> m_plugins;
	std::unordered_map<std::string, void*> m_handles;
};
