#pragma once

#include <common/IPlugin.h>

class PluginA : public IPlugin
{
public:
	const char* name() const;
	void sayHelloTo( const char* username );
	int doSomething( int a, int b );
};

#include <common/PluginDefine.h>
#include <common/Export.h>
DEFINE_GET_INSTANCE( PluginA, API_EXPORT )

// Optional.
#include <common/dllmain.h>
