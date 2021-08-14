#include "PluginB.h"
#include <iostream>

const char* PluginB::name() const
{
	return "PluginB";
}

int PluginB::doSomething( int a, int b )
{
	return a * b;
}

void PluginB::sayHelloTo( const char* username )
{
	std::cout << "Hello from PluginB, " << username << std::endl;
}
