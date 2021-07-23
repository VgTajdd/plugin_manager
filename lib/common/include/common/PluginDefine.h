#pragma once

// This is a macro for creating a getInstance function for a given plugin.
// Need C linkage here (extern "C" to avoid mangled names of the load function on windows,
// see https://stackoverflow.com/questions/19422550/why-getprocaddress-is-not-working
// This is the only function that will be exported.
// 'exportStatement' is needed for Windows.
#define DEFINE_GET_INSTANCE(className, exportStatement)	\
extern "C" exportStatement								\
IPlugin* getInstance()									\
{														\
	static className instance;							\
	return &instance;									\
}
