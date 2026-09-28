#pragma once

/**
	* @brief Defines the ENGINE_API macro for exporting or importing symbols when building or using the engine DLL.
	*/
#if defined(_WIN32)

/**
	* @brief If ENGINE_BUILD_DLL is defined, export symbols; otherwise, import symbols.
	*/
#if defined(ENGINE_BUILD_DLL)
#define ENGINE_API __declspec(dllexport)
#else
#define ENGINE_API __declspec(dllimport)
#endif

/**
	* @brief If not on Windows, define ENGINE_API as empty.
	*/
#else
#define ENGINE_API
#endif