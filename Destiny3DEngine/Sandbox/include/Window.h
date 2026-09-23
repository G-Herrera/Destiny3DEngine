#pragma once

#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif

#ifndef NOMINMAX
#define NOMINMAX
#endif

#include <Windows.h>

class Window final {
public:
	Window() = default;
	~Window();

	Window(const Window&) = delete;
	Window& operator=(const Window&) = delete;
	/**
		* @brief Crea una ventana de Windows con el tamaño especificado.
		* @param insstance El identificador de la instancia de la aplicación.
		* @param title El título de la ventana.
		* @param width El ancho de la ventana en píxeles.
		* @param height La altura de la ventana en píxeles.
		* @return true si la ventana se creó correctamente, false en caso contrario.
		*/
	bool 
	Create(HINSTANCE instance, const wchar_t* title, UINT width, UINT height) noexcept;

	/**
		* @brief Muestra la ventana en la pantalla.
		* @param showCommand El comando de visualización de la ventana (por ejemplo, SW_SHOW).
		*/
	void
	Show(int showCommand) noexcept;

	/**
		* @brief Actualiza la ventana, forzando un repintado.
		*/
	void 
	Destroy() noexcept;

	/**
		* @brief Procesa los mensajes de la ventana.
		* @return true si se procesaron los mensajes correctamente, false si se recibió un mensaje de cierre.
		*/
	bool 
	ProcessMessages() noexcept;

	/**
		* @brief Obtiene el identificador de la ventana.
		* @return El identificador de la ventana (HWND).
		*/
	HWND
	GetHandle() const noexcept { return m_windowHandle; }
	
	/**
		* @brief Comprueba si la ventana está minimizada.
		* @return true si la ventana está minimizada, false en caso contrario.
		*/
	bool 
	IsMinimized() const noexcept;

private:
	static LRESULT CALLBACK WindowProcedure(HWND window, UINT message, WPARAM wParam, LPARAM lParam);
	HWND m_windowHandle = nullptr; ///< El identificador de la ventana (HWND). Utilizado para interactuar con la API de Windows.

	static constexpr const wchar_t* ClassName = L"Destiny 3D Engine Window"; ///< Nombre de la clase de ventana.

	HINSTANCE m_instance = nullptr; ///< El identificador de la instancia de la aplicación (HINSTANCE). Utilizado para registrar la clase de ventana y crear la ventana.
	bool m_classRegistered = false; ///< Indica si la clase de ventana ha sido registrada correctamente.
};