
#include<iostream>
#include<string>

#pragma once
#if defined(_MSC_VER)
	//microsoft
	#if defined(foo_EXPORTS)
		#define FOO_API __declspec(dllexport)
	#else 
		#define FOO_API __declspec(dllimport)
	#endif
#elif defined(__GNUC__)
	//GNU Compiler
	#if defined(foo_EXPORTS)
		#define FOO_API __attribute__((visibility("default")))
	#else
		#define FOO_API
	#endif
#else
	//  do nothing and hope for the best?
	#if defined(foo_EXPORTS)
		#define FOO_API
	#else
		#define FOO_API
	#pragma warning Unknown dynamic link import/export semantics.
	#endif
#endif

 extern "C" {
	 FOO_API void print(std::string="hello?");
 }
