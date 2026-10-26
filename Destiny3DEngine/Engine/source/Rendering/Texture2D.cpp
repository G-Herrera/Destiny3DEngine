//#define STB_IMAGE_IMPLEMENTATION
//#include "stb_image.h"
#include "Rendering/Texture2D.h"
#include "Rendering/Device.h"
#include "Rendering/DeviceContext.h"

HRESULT 
Texture2D::init(Device& device, 
                const std::string& textureName, 
                ExtensionType extensionType) {
  if (!device.getDevice()) {
    ERROR("Texture", "init", "Device is null.");
    return E_POINTER;
  }
  if (textureName.empty()) {
    ERROR("Texture", "init", "Texture name cannot be empty.");
    return E_INVALIDARG;
  }

  HRESULT hr = S_OK;
  switch (extensionType) {
  case DDS:
    break;
  case PNG: {
    m_textureName = textureName + ".png";
    hr = InitTextureFromImage(device, m_textureName, *this);
    break;
  }
  case JPG: {
    m_textureName = textureName + ".jpg";
    hr = InitTextureFromImage(device, m_textureName, *this);
    break;
  }
  default:
    ERROR("Texture", "init", "Unsuported extension type");
    return E_INVALIDARG;
  }

  return hr;
}

HRESULT 
Texture2D::init(Device& device, 
                unsigned int width, 
                unsigned int height, 
                DXGI_FORMAT Format, 
                unsigned int BindFlags,
                unsigned int sampleCount, 
                unsigned int qualityLevels) {
  if (!device.getDevice()) {
    ERROR("Texture", "init", "Device is null.");
    return E_POINTER;
  }
  if (width == 0 || height == 0) {
    ERROR("Texture", "init", "Width and height must be greater than 0.");
    return E_INVALIDARG;
  }

  D3D11_TEXTURE2D_DESC desc;
  memset(&desc, 0, sizeof(desc));
  desc.Width = width;
  desc.Height = height;
  desc.Format = Format;
  desc.MipLevels = 1;
  desc.ArraySize = 1;
  desc.SampleDesc.Count = sampleCount;
  desc.SampleDesc.Quality = qualityLevels;
  desc.Usage = D3D11_USAGE_DEFAULT;
  desc.BindFlags = BindFlags;
  desc.CPUAccessFlags = 0;
  desc.MiscFlags = 0;

  HRESULT hr = device.CreateTexture2D(&desc, nullptr, &m_texture);

  if (FAILED(hr)) {
    ERROR("Tetxture", 
          "init", 
          ("Failed to create texture with specified name HRESULT: " + 
           std::to_string(hr)).c_str());
    return hr;
  }
  return S_OK;
}
