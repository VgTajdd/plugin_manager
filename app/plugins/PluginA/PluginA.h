// ========================================================================= //
// Copyright (c) 2021 Agustin Jesus Durand Diaz.                             //
// This code is licensed under the MIT License.                              //
// PluginA.h                                                                 //
// ========================================================================= //

#pragma once

#include <common/IPlugin.h>
#include <app/ICustomPlugin.h>

class PluginA : public ICustomPlugin
{
public:
	const char* name() const override;
	void sayHelloTo( const char* username ) override;
	int doSomething( int a, int b ) override;
};

#include <common/PluginDefines.h>
#include <common/Export.h>
DEFINE_GET_INSTANCE( PluginA, API_EXPORT )

// Optional.
#include <common/dllmain.h>
