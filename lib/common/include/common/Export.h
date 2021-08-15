// ========================================================================= //
// Copyright (c) 2021 Agustin Jesus Durand Diaz.                             //
// This code is licensed under the MIT License.                              //
// Export.h                                                                  //
// ========================================================================= //

#ifndef API_EXPORT_H
#define API_EXPORT_H

#ifdef API_STATIC_DEFINE
#  define API_EXPORT
#  define API_NO_EXPORT
#else
#  ifndef API_EXPORT
#    ifdef API_EXPORTS
/* We are building this library */
#if defined(_MSC_VER)
#      define API_EXPORT __declspec(dllexport)
#elif defined(__GNUC__)
#      define API_EXPORT __attribute__((visibility("default")))
#else
#      pragma warning Unknown dynamic link import/export semantics.
#endif
#    else
/* We are using this library */
#if defined(_MSC_VER)
#      define API_EXPORT __declspec(dllimport)
#else
#      define API_EXPORT
#endif
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
