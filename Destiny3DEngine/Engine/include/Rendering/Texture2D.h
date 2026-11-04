#pragma once
#include "Engine/Prerequisites.h"

/**
 * @brief Represents a 2D texture that can be used for rendering in Direct3D 11.
 * 
 * This class encapsulates the creation, updating, and rendering of a Direct3D 11 2D texture.
 */
class Device;
class DeviceContext;
class SwapChain;

class 
Texture2D {
public:
  Texture2D() noexcept = default;
  ~Texture2D();

  Texture2D(const Texture2D&) = delete;
  Texture2D& operator=(const Texture2D&) = delete;

  Texture2D(Texture2D&&) = delete;
  Texture2D& operator=(Texture2D&&) = delete;

  /**
   * @brief Initializes the texture with the provided device, texture name, and extension type.
   * 
   * @param device The Direct3D device used to create the texture.
   * @param textureName The name of the texture file to load.
   * @param extensionType The type of the texture file (e.g., DDS, PNG, JPG).
   * @return HRESULT Indicates success or failure of the initialization.
	 */
  HRESULT 
  init(Device& device, 
       const std::string& textureName,
       ExtensionType extensionType) noexcept;

  /**
   * @brief Initializes the texture from an image file.
   * 
   * @param device The Direct3D device used to create the texture.
   * @param fullPath The full path to the image file.
   * @param texture The Texture2D object to initialize.
   * @return HRESULT Indicates success or failure of the initialization.
	 */
  HRESULT 
  InitTextureFromImage(Device& device, const std::string& fullPath, Texture2D& texture);

  /**
   * @brief Initializes the texture with the specified width, height, format, bind flags, sample count, and quality levels.
   * 
   * @param device The Direct3D device used to create the texture.
   * @param width The width of the texture in pixels.
   * @param height The height of the texture in pixels.
   * @param Format The DXGI format of the texture.
   * @param BindFlags The bind flags specifying how the texture will be used (e.g., shader resource, render target).
   * @param sampleCount The number of samples per pixel (default is 1).
   * @param qualityLevels The number of quality levels for multisampling (default is 0).
   * @return HRESULT Indicates success or failure of the initialization.
	 */
  HRESULT 
  init(Device& device, 
       unsigned int width, 
       unsigned int height, 
       DXGI_FORMAT Format, 
       unsigned int BindFlags, 
       unsigned int sampleCount = 1, 
       unsigned int qualityLevels = 0);

  /**
   * @brief Initializes the texture by referencing another texture and specifying a format.
   * 
   * @param device The Direct3D device used to create the texture.
   * @param textureRef The reference texture to initialize from.
   * @param format The DXGI format of the new texture.
   * @return HRESULT Indicates success or failure of the initialization.
	 */
  HRESULT 
  init(Device& device, Texture2D& textureRef, DXGI_FORMAT format);

  /**
   * @brief Updates the texture with new data.
	 */
  void 
  update();

  /**
   * @brief Renders the texture by setting it to the pixel shader stage.
   * 
   * @param deviceContext The Direct3D device context used for rendering.
   * @param StartSlot The starting slot for binding the texture.
   * @param NumViews The number of shader resource views to bind.
	 */
  void 
  render(DeviceContext& deviceContext, unsigned int StartSlot, unsigned int NumViews);

  /**
   * @brief Destroys the texture and releases associated resources.
	 */
  void 
  destroy() noexcept;

  /**
   * @brief Creates a cubemap texture from six image files.
   * 
   * @param device The Direct3D device used to create the cubemap.
   * @param deviceContext The Direct3D device context used for rendering.
   * @param facePaths An array of six file paths for the cubemap faces (order: +X, -X, +Y, -Y, +Z, -Z).
   * @param generateMips A flag indicating whether to generate mipmaps for the cubemap (default is false).
   * @return HRESULT Indicates success or failure of the cubemap creation.
	 */
  HRESULT 
  CreateCubemap(Device& device, 
                DeviceContext& deviceContext, 
                const std::array<std::string, 6>& facePaths, 
                bool generateMips /*=false*/);

	/**
   * @brief Creates a shader resource view for a specific face of a cubemap texture.
   * 
   * @param device The Direct3D device used to create the shader resource view.
   * @param cubemapTex The cubemap texture from which to create the shader resource view.
   * @param format The DXGI format of the shader resource view.
   * @param faceIndex The index of the cubemap face (0-5) for which to create the shader resource view.
   * @param mipLevels The number of mip levels to include in the shader resource view (default is 1).
   * @return ID3D11ShaderResourceView* A pointer to the created shader resource view, or nullptr on failure.
	 */
  ID3D11ShaderResourceView* 
  CreateCubemapFaveSRV(ID3D11Device* device,
                       ID3D11Texture2D* cubemapTex,
                       DXGI_FORMAT format,
                       unsigned int faceIndex,
                       unsigned int mipLevels = 1);
  /**
   * @brief Gets the underlying ID3D11Texture2D.
   * @return ID3D11Texture2D* The underlying Direct3D texture.
	 */
  ID3D11Texture2D* 
  GetTexture() const noexcept {
    return m_texture;
  }

  /**
   * @brief Gets the address of the underlying ID3D11Texture2D.
   * @return ID3D11Texture2D** The address of the underlying Direct3D texture.
	 */
  ID3D11Texture2D** 
  GetTextureAdress() noexcept {
    return &m_texture;
  }

public:
	ID3D11Texture2D* m_texture = nullptr;///> The underlying Direct3D texture.

	ID3D11ShaderResourceView* m_textureFromImg = nullptr;///> The shader resource view created from the image file.

	std::string m_textureName;///> The name of the texture file.
  
private:

};
