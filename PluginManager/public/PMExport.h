#ifndef PM_EXPORT_H
#define PM_EXPORT_H

#ifdef PM_STATIC_DEFINE
#  define PM_EXPORT
#  define PM_NO_EXPORT
#else
#  ifndef PM_EXPORT
#    ifdef PM_EXPORTS
/* We are building this library */
#      define PM_EXPORT __declspec(dllexport)
#    else
/* We are using this library */
#      define PM_EXPORT __declspec(dllimport)
#    endif
#  endif

#  ifndef PM_NO_EXPORT
#    define PM_NO_EXPORT
#  endif
#endif

#ifndef PM_DEPRECATED
#  define PM_DEPRECATED __declspec(deprecated)
#endif

#ifndef PM_DEPRECATED_EXPORT
#  define PM_DEPRECATED_EXPORT PM_EXPORT PM_DEPRECATED
#endif

#ifndef PM_DEPRECATED_NO_EXPORT
#  define PM_DEPRECATED_NO_EXPORT PM_NO_EXPORT PM_DEPRECATED
#endif

#if 0 /* DEFINE_NO_DEPRECATED */
#  ifndef PM_NO_DEPRECATED
#    define PM_NO_DEPRECATED
#  endif
#endif

#endif /* PM_EXPORT_H */
