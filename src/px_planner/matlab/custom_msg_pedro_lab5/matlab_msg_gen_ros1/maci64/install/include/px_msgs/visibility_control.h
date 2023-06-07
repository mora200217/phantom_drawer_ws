#ifndef PX_MSGS__VISIBILITY_CONTROL_H_
#define PX_MSGS__VISIBILITY_CONTROL_H_
#if defined _WIN32 || defined __CYGWIN__
  #ifdef __GNUC__
    #define PX_MSGS_EXPORT __attribute__ ((dllexport))
    #define PX_MSGS_IMPORT __attribute__ ((dllimport))
  #else
    #define PX_MSGS_EXPORT __declspec(dllexport)
    #define PX_MSGS_IMPORT __declspec(dllimport)
  #endif
  #ifdef PX_MSGS_BUILDING_LIBRARY
    #define PX_MSGS_PUBLIC PX_MSGS_EXPORT
  #else
    #define PX_MSGS_PUBLIC PX_MSGS_IMPORT
  #endif
  #define PX_MSGS_PUBLIC_TYPE PX_MSGS_PUBLIC
  #define PX_MSGS_LOCAL
#else
  #define PX_MSGS_EXPORT __attribute__ ((visibility("default")))
  #define PX_MSGS_IMPORT
  #if __GNUC__ >= 4
    #define PX_MSGS_PUBLIC __attribute__ ((visibility("default")))
    #define PX_MSGS_LOCAL  __attribute__ ((visibility("hidden")))
  #else
    #define PX_MSGS_PUBLIC
    #define PX_MSGS_LOCAL
  #endif
  #define PX_MSGS_PUBLIC_TYPE
#endif
#endif  // PX_MSGS__VISIBILITY_CONTROL_H_
// Generated 06-Jun-2023 01:32:47
// Copyright 2019-2020 The MathWorks, Inc.
