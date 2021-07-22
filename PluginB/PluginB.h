#pragma once

#include <common/IPlugin.h>

class PluginB : public IPlugin
{
public:
	const char* name() const;
	void sayHelloTo( const char* username );
	int doSomething( int a, int b );
private:
	void helperMethod( int a, int b );
};

#include <common/PluginDefine.h>
#include <common/Export.h>
DEFINE_GET_INSTANCE( PluginB, API_EXPORT )