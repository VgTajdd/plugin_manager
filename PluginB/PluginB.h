#pragma once

#include <Common/IPlugin.h>

class PluginB : public IPlugin
{
public:
	const char* name() const;
	void sayHelloTo( const char* username );
	int doSomething( int a, int b );
private:
	void helperMethod( int a, int b );
};

#include <Common/PluginDefine.h>
#include "PluginBExport.h"
DEFINE_GET_INSTANCE( PluginB, PLUGIN_B_EXPORT )