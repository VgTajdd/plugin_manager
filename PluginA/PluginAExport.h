#ifndef PLUGIN_A_EXPORT_H
#define PLUGIN_A_EXPORT_H

#ifdef PLUGIN_A_STATIC_DEFINE
#  define PLUGIN_A_EXPORT
#  define PLUGIN_A_NO_EXPORT
#else
#  ifndef PLUGIN_A_EXPORT
#    ifdef PLUGIN_A_EXPORTS
/* We are building this library */
#      define PLUGIN_A_EXPORT __declspec(dllexport)
#    else
/* We are using this library */
#      define PLUGIN_A_EXPORT __declspec(dllimport)
#    endif
#  endif

#  ifndef PLUGIN_A_NO_EXPORT
#    define PLUGIN_A_NO_EXPORT
#  endif
#endif

#ifndef PLUGIN_A_DEPRECATED
#  define PLUGIN_A_DEPRECATED __declspec(deprecated)
#endif

#ifndef PLUGIN_A_DEPRECATED_EXPORT
#  define PLUGIN_A_DEPRECATED_EXPORT PLUGIN_A_EXPORT PLUGIN_A_DEPRECATED
#endif

#ifndef PLUGIN_A_DEPRECATED_NO_EXPORT
#  define PLUGIN_A_DEPRECATED_NO_EXPORT PLUGIN_A_NO_EXPORT PLUGIN_A_DEPRECATED
#endif

#if 0 /* DEFINE_NO_DEPRECATED */
#  ifndef PLUGIN_A_NO_DEPRECATED
#    define PLUGIN_A_NO_DEPRECATED
#  endif
#endif

#endif /* PLUGIN_A_EXPORT_H */
