#include <gtest/gtest.h>

#include <common/IPlugin.h>
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

    float values[2];
    size_t i{ 0 };

    for ( const auto pluginFilename : plugins )
    {
        if ( IPluginManager::Get()->loadPlugin( pluginFilename ) )
        {
            auto plugin = IPluginManager::Get()->getPlugin( pluginFilename );
            plugin->sayHelloTo( "Agustin" );
            values[i++] = plugin->doSomething( 4, 5 );
            IPluginManager::Get()->unloadPlugin( pluginFilename );
        }
    }

    EXPECT_EQ( 9, values[0] );
    EXPECT_EQ( 20, values[1] );
}
