// ========================================================================= //
// Copyright (c) 2021 Agustin Jesus Durand Diaz.                             //
// This code is licensed under the MIT License.                              //
// PluginB.h                                                                 //
// ========================================================================= //

#pragma once

#include <common/IPlugin.h>

class PluginB : public IPlugin
{
public:
	const char* name() const override;

private:
	void helperMethod( int a, int b );
};

#include <common/PluginDefines.h>
#include <common/Export.h>
DEFINE_GET_INSTANCE( PluginB, API_EXPORT )
