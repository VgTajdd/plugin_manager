#ifndef PLUGIN_B_EXPORT_H
#define PLUGIN_B_EXPORT_H

#ifdef PLUGIN_B_STATIC_DEFINE
#  define PLUGIN_B_EXPORT
#  define PLUGIN_B_NO_EXPORT
#else
#  ifndef PLUGIN_B_EXPORT
#    ifdef PLUGIN_B_EXPORTS
/* We are building this library */
#      define PLUGIN_B_EXPORT __declspec(dllexport)
#    else
/* We are using this library */
#      define PLUGIN_B_EXPORT __declspec(dllimport)
#    endif
#  endif

#  ifndef PLUGIN_B_NO_EXPORT
#    define PLUGIN_B_NO_EXPORT
#  endif
#endif

#ifndef PLUGIN_B_DEPRECATED
#  define PLUGIN_B_DEPRECATED __declspec(deprecated)
#endif

#ifndef PLUGIN_B_DEPRECATED_EXPORT
#  define PLUGIN_B_DEPRECATED_EXPORT PLUGIN_B_EXPORT PLUGIN_B_DEPRECATED
#endif

#ifndef PLUGIN_B_DEPRECATED_NO_EXPORT
#  define PLUGIN_B_DEPRECATED_NO_EXPORT PLUGIN_B_NO_EXPORT PLUGIN_B_DEPRECATED
#endif

#if 0 /* DEFINE_NO_DEPRECATED */
#  ifndef PLUGIN_B_NO_DEPRECATED
#    define PLUGIN_B_NO_DEPRECATED
#  endif
#endif

#endif /* PLUGIN_B_EXPORT_H */
