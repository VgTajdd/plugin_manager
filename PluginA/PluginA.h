#pragma once

#include <Common/IPlugin.h>

class PluginA : public IPlugin
{
public:
	const char* name() const;
	void sayHelloTo( const char* username );
	int doSomething( int a, int b );
};

#include <Common/PluginDefine.h>
#include "PluginAExport.h"
DEFINE_GET_INSTANCE( PluginA, PLUGIN_A_EXPORT )

// Optional.
#include <Common/dllmain.h>