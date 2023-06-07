#ifndef ALV__VISIBILITY_CONTROL_H_
#define ALV__VISIBILITY_CONTROL_H_
#if defined _WIN32 || defined __CYGWIN__
  #ifdef __GNUC__
    #define ALV_EXPORT __attribute__ ((dllexport))
    #define ALV_IMPORT __attribute__ ((dllimport))
  #else
    #define ALV_EXPORT __declspec(dllexport)
    #define ALV_IMPORT __declspec(dllimport)
  #endif
  #ifdef ALV_BUILDING_LIBRARY
    #define ALV_PUBLIC ALV_EXPORT
  #else
    #define ALV_PUBLIC ALV_IMPORT
  #endif
  #define ALV_PUBLIC_TYPE ALV_PUBLIC
  #define ALV_LOCAL
#else
  #define ALV_EXPORT __attribute__ ((visibility("default")))
  #define ALV_IMPORT
  #if __GNUC__ >= 4
    #define ALV_PUBLIC __attribute__ ((visibility("default")))
    #define ALV_LOCAL  __attribute__ ((visibility("hidden")))
  #else
    #define ALV_PUBLIC
    #define ALV_LOCAL
  #endif
  #define ALV_PUBLIC_TYPE
#endif
#endif  // ALV__VISIBILITY_CONTROL_H_
// Generated 05-Jun-2023 13:05:05
// Copyright 2019-2020 The MathWorks, Inc.
