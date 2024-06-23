// ========================================================================= //
// Copyright (c) 2021 Agustin Jesus Durand Diaz.                             //
// This code is licensed under the MIT License.                              //
// IPlugin.h                                                                 //
// ========================================================================= //

#pragma once

class IPlugin
{
public:
	virtual ~IPlugin() {};
	virtual const char* name() const = 0;
};
