#include <IPluginManager.h>
#include <Common/IPlugin.h>

#include <iostream>
#include <thread>

int main()
{
	const char* plugins[] = { "pluginA.dll", "pluginB.dll"/*, "pluginC.dll"*/ };

	std::cout << "Starting Plugin Manager..."<< std::endl;
	std::this_thread::sleep_for( std::chrono::milliseconds( 2000 ) );
	for ( const auto pluginFilename : plugins )
	{
		std::cout << "========= " << pluginFilename << " =========" << std::endl;
		std::this_thread::sleep_for( std::chrono::milliseconds( 1000 ) );
		if ( IPluginManager::Get()->loadPlugin( pluginFilename ) )
		{
			auto plugin = IPluginManager::Get()->getPlugin( pluginFilename );
			std::this_thread::sleep_for( std::chrono::milliseconds( 1000 ) );
			std::cout << "Plugin name: " << plugin->name() << std::endl;
			std::this_thread::sleep_for( std::chrono::milliseconds( 1000 ) );
			plugin->sayHelloTo( "Agustin" );
			std::this_thread::sleep_for( std::chrono::milliseconds( 1000 ) );
			std::cout << "Plugin->doSomething(4, 5) = " << plugin->doSomething( 4, 5 ) << std::endl;
			std::this_thread::sleep_for( std::chrono::milliseconds( 1000 ) );
			IPluginManager::Get()->unloadPlugin( pluginFilename );
			std::this_thread::sleep_for( std::chrono::milliseconds( 1000 ) );
			std::cout << std::endl;
		}
	}

	std::cin.get();
	return 0;
}