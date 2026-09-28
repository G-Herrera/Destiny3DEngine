#pragma once

#include "API.h"
#include <cstdint>
#include <Windows.h>

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

class ENGINE_API 
Engine final {
public:
	Engine() noexcept;
	~Engine() noexcept;

	Engine(const Engine&) = delete;
	Engine& operator=(const Engine&) = delete;

	Engine(Engine&&) = delete;
	Engine& operator=(Engine&&) = delete;

	/**
		* @brief Initializes the engine with the given native window handle and dimensions.
		* 
		* @param nativeWindow A pointer to the native window handle.
		* @param width The width of the window.
		* @param height The height of the window.
		* @return true if the engine was successfully initialized, false otherwise.
		*/
	bool 
	Initialize(void* nativeWindow,	std::uint32_t width, std::uint32_t height) noexcept;

	/**
		* @brief Updates the engine state. This function should be called once per frame.
		*/
	void 
	Render() noexcept;

	/**
		* @brief Renders the current frame. This function should be called once per frame after Update().
		*/
	void 
	Shutdown() noexcept;

private: 
	struct Implementation; ///> Forward declaration of the implementation struct to hide implementation details.
	Implementation* m_Implementation = nullptr; ///> Pointer to the implementation struct, used for the Pimpl idiom to hide implementation details.
};