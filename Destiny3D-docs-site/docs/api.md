# Destiny3DEngine API {#mainpage}

**Destiny3DEngine** is an educational, evolving 3D rendering engine written in C++ for Windows, using Direct3D 11.

[Project website](../index.html) · [Source code](https://github.com/G-Herrera/Destiny3DEngine/tree/engineImplementation)

## Architecture

- **Engine** — application orchestration and rendering loop.
- **Device** — Direct3D device and graphics-resource creation.
- **DeviceContext** — graphics pipeline commands.
- **SwapChain** — frame presentation.
- **Buffer** — vertex and index buffer management.
- **Texture2D** — texture and depth resources.
- **MeshComponent** — CPU-side mesh geometry.
- **Sandbox** — Windows test executable (not part of API generation).

Browse the **Classes**, **Files**, and **Class Hierarchy** sections to inspect the actual C++ APIs.

## Build

Open `Destiny3DEngine/Destiny3DEngine.sln` with Visual Studio and a suitable Windows SDK. The website is static documentation; it does not run Direct3D code in the browser.

## Doxygen comments

Use this comment style for new public APIs:

```cpp
/**
 * @brief Creates a GPU resource from mesh geometry.
 * @param device Wrapper around the Direct3D device.
 * @param mesh Input mesh.
 * @return HRESULT indicating success or failure.
 */
```

Note: `EXTRACT_ALL = YES` ensures existing classes are listed even before every method has been documented. The API is under active development.
