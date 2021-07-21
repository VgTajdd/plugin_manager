#pragma once

#include "PMExport.h"

class PM_EXPORT IPluginManager
{
public:
	static IPluginManager* Get();
	virtual ~IPluginManager() {};
	virtual bool loadPlugin( const char* filename ) = 0;
	virtual bool unloadPlugin( const char* filename ) = 0;
	virtual class IPlugin* getPlugin( const char* filename ) = 0;
};