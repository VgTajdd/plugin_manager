// ========================================================================= //
// Copyright (c) 2021 Agustin Jesus Durand Diaz.                             //
// This code is licensed under the MIT License.                              //
// PluginDefines.h                                                           //
// ========================================================================= //

#pragma once

#define TO_STR(x) #x

#define GET_INSTANCE getInstance
#define GET_INSTANCE_STR TO_STR(getInstance)

// This is a macro for creating a getInstance function for a given plugin.
// Need C linkage here (extern "C" to avoid mangled names of the load function on windows,
// see https://stackoverflow.com/questions/19422550/why-getprocaddress-is-not-working
// This is the only function that will be exported.
#define DEFINE_GET_INSTANCE(className, exportStatement)	\
extern "C" exportStatement								\
IPlugin* GET_INSTANCE()									\
{														\
	static className instance;							\
	return &instance;									\
}
