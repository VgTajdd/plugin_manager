// ========================================================================= //
// Copyright (c) 2021 Agustin Jesus Durand Diaz.                             //
// This code is licensed under the MIT License.                              //
// PluginManager.h                                                           //
// ========================================================================= //

#pragma once

#include "plugin_manager/IPluginManager.h"
#include <unordered_map>

class IPlugin;

class PluginManager : public IPluginManager
{
public:
	~PluginManager() override;
	IPlugin* loadPlugin( const char* filename ) override;
	bool unloadPlugin( const char* filename ) override;
	IPlugin* getPlugin( const char* filename ) override;
private:
	std::unordered_map<std::string, IPlugin*> m_plugins;
	std::unordered_map<std::string, void*> m_handles;
};
