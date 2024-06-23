// ========================================================================= //
// Copyright (c) 2021 Agustin Jesus Durand Diaz.                             //
// This code is licensed under the MIT License.                              //
// PluginA.cpp                                                               //
// ========================================================================= //

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
