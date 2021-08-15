// ========================================================================= //
// Copyright (c) 2021 Agustin Jesus Durand Diaz.                             //
// This code is licensed under the MIT License.                              //
// PluginB.cpp                                                               //
// ========================================================================= //

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
