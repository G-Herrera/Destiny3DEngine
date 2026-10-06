#pragma once
#include "API.h"
#include <cstdint>
#include <Windows.h>
#include <DirectXMath.h>
#include <chrono>
#include <d3d11.h>
#include <d3dcompiler.h>
#include <cstddef>
#include <new>

// MACROS
#define SAFE_RELEASE(x) if(x != nullptr) x->Release(); x = nullptr;

#define MESSAGE( classObj, method, state )   \
{                                            \
   std::wostringstream os_;                  \
   os_ << classObj << "::" << method << " : " << "[CREATION OF RESOURCE " << ": " << state << "] \n"; \
   OutputDebugStringW( os_.str().c_str() );  \
}

#define ERROR(classObj, method, errorMSG)                     \
{                                                             \
    try {                                                     \
        std::wostringstream os_;                              \
        os_ << L"ERROR : " << classObj << L"::" << method     \
            << L" : " << errorMSG << L"\n";                   \
        OutputDebugStringW(os_.str().c_str());                \
    } catch (...) {                                           \
        OutputDebugStringW(L"Failed to log error message.\n");\
    }                                                         \
}

extern "C" {
	ENGINE_API bool
		Engine_Initialize(HWND windowHandle, int width, int height) noexcept;

	ENGINE_API void
		Engine_Update() noexcept;

	ENGINE_API void
		Engine_Render() noexcept;

	ENGINE_API void
		Engine_Shutdown() noexcept;
}