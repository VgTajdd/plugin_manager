// ========================================================================= //
// Copyright (c) 2021 Agustin Jesus Durand Diaz.                             //
// This code is licensed under the MIT License.                              //
// main.cpp                                                                  //
// ========================================================================= //

#include <iostream>
#include <plugin_manager/IPluginManager.h>
#include <common/IPlugin.h>
#include "app/ICustomPlugin.h"

int main()
{
	const char* plugins[] = { "pluginA", "pluginB", "pluginC" };

	std::cout << "Starting Plugin Manager..." << std::endl;
	for ( const auto pluginFilename : plugins )
	{
		std::cout << "========= " << pluginFilename << " =========" << std::endl;
		if ( IPlugin* plugin = IPluginManager::Get()->loadPlugin( pluginFilename ) )
		{
			std::cout << "Plugin name: " << plugin->name() << std::endl;
			if ( ICustomPlugin* customPlugin = dynamic_cast<ICustomPlugin*>( plugin ) )
			{
				customPlugin->sayHelloTo( "Agustin" );
				std::cout << "Plugin->doSomething(4, 5) = " << customPlugin->doSomething( 4, 5 ) << std::endl;
			}
			else
			{
				std::cout << "Plugin does not implement ICustomPlugin." << std::endl;
			}
			IPluginManager::Get()->unloadPlugin( pluginFilename );
		}
	}

	std::cin.get();
	return 0;
}
