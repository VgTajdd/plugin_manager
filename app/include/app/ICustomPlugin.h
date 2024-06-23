# pragma once

#include <common/IPlugin.h>

class ICustomPlugin : public IPlugin
{
public:
	virtual void sayHelloTo( const char* username ) = 0;
	virtual int doSomething( int a, int b ) = 0;
};
