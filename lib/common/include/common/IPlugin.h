#pragma once

class IPlugin
{
public:
	virtual ~IPlugin() {};
	virtual void sayHelloTo( const char* username ) = 0;
	virtual const char* name() const = 0;
	virtual int doSomething( int a, int b ) = 0;
};
