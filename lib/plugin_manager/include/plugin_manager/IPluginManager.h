// ========================================================================= //
// Copyright (c) 2021 Agustin Jesus Durand Diaz.                             //
// This code is licensed under the MIT License.                              //
// IPluginManager.h                                                          //
// ========================================================================= //

#pragma once

#include <common/Export.h>

class API_EXPORT IPluginManager
{
public:
	static IPluginManager* Get();
	virtual ~IPluginManager() {};
	virtual bool loadPlugin( const char* filename ) = 0;
	virtual bool unloadPlugin( const char* filename ) = 0;
	virtual class IPlugin* getPlugin( const char* filename ) = 0;
};
