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
	virtual void sayHelloTo( const char* username ) = 0;
	virtual const char* name() const = 0;
	virtual int doSomething( int a, int b ) = 0;
};
