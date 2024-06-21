#include <gtest/gtest.h>

#include <common/IPlugin.h>
#include <app/ICustomPlugin.h>
#include <plugin_manager/IPluginManager.h>

TEST( PluginManagerTest, PluginName )
{
	char pluginName[20];
	if ( IPluginManager::Get()->loadPlugin( "pluginA" ) )
	{
		auto plugin = IPluginManager::Get()->getPlugin( "pluginA" );
		strcpy( pluginName, plugin->name() );
		IPluginManager::Get()->unloadPlugin( "pluginA" );
	}

	EXPECT_STREQ( "PluginA", pluginName );
}

TEST( PluginManagerTest, DoSomething )
{
	const char* plugins[] = { "pluginA", "pluginB" };

	float values[2] = { 0.0f, 0.0f };
	size_t i{ 0 };

	for ( const auto pluginFilename : plugins )
	{
		if ( IPlugin* plugin = IPluginManager::Get()->loadPlugin( pluginFilename ) )
		{
			if ( ICustomPlugin* customPlugin = dynamic_cast<ICustomPlugin*>( plugin ) )
			{
				customPlugin->sayHelloTo( "Agustin" );
				values[i++] = customPlugin->doSomething( 4, 5 );
			}
			else
			{
				std::cout << "Plugin does not implement ICustomPlugin." << std::endl;
			}
			IPluginManager::Get()->unloadPlugin( pluginFilename );
		}
	}

	EXPECT_EQ( 9, values[0] );
	EXPECT_EQ( 0, values[1] );
}
