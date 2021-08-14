#include "PluginA.h"
#include <iostream>

const char* PluginA::name() const
{
	return "PluginA";
}

int PluginA::doSomething( int a, int b )
{
	return a + b;
}

void PluginA::sayHelloTo( const char* username )
{
	std::cout << "Hello from PluginA, " << username << std::endl;
}
