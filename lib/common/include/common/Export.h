#ifndef API_EXPORT_H
#define API_EXPORT_H

#ifdef API_STATIC_DEFINE
#  define API_EXPORT
#  define API_NO_EXPORT
#else
#  ifndef API_EXPORT
#    ifdef API_EXPORTS
/* We are building this library */
#      define API_EXPORT __declspec(dllexport)
#    else
/* We are using this library */
#      define API_EXPORT __declspec(dllimport)
#    endif
#  endif

#  ifndef API_NO_EXPORT
#    define API_NO_EXPORT
#  endif
#endif

#ifndef API_DEPRECATED
#  define API_DEPRECATED __declspec(deprecated)
#endif

#ifndef API_DEPRECATED_EXPORT
#  define API_DEPRECATED_EXPORT API_EXPORT API_DEPRECATED
#endif

#ifndef API_DEPRECATED_NO_EXPORT
#  define API_DEPRECATED_NO_EXPORT API_NO_EXPORT API_DEPRECATED
#endif

#if 0 /* DEFINE_NO_DEPRECATED */
#  ifndef API_NO_DEPRECATED
#    define API_NO_DEPRECATED
#  endif
#endif

#endif /* API_EXPORT_H */
