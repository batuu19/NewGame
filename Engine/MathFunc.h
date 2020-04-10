#pragma once

#ifdef MATHLIBRARY_EXPORTS
#define MATHLIBRARY_API __declspec(dllexport)
#else
#define MATHLIBRARY_API __declspec(dllimport)
#endif

MATHLIBRARY_API int Add(const int a, const int b);
MATHLIBRARY_API int Sub(const int a, const int b);
MATHLIBRARY_API int Mul(const int a, const int b);
MATHLIBRARY_API int Div(const int a, const int b);