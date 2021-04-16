#include <IPluginManager.h>
#include <Common/IPlugin.h>

#include <iostream>

int main()
{
	const char* plugins[] = { "pluginA.dll", "pluginB.dll", "pluginC.dll" };

	std::cout << "Starting Plugin Manager..."<< std::endl;
	for ( const auto pluginFilename : plugins )
	{
		std::cout << "========= " << pluginFilename << " =========" << std::endl;
		if ( IPluginManager::Get()->loadPlugin( pluginFilename ) )
		{
			auto plugin = IPluginManager::Get()->getPlugin( pluginFilename );
			std::cout << "Plugin name: " << plugin->name() << std::endl;
			plugin->sayHelloTo( "Agustin" );
			std::cout << "Plugin->doSomething(4, 5) = " << plugin->doSomething( 4, 5 ) << std::endl;
			IPluginManager::Get()->unloadPlugin( pluginFilename );
		}
	}

	std::cin.get();
	return 0;
}