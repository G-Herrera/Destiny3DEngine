#include "Rendering/RenderTargetView.h"
#include "Rendering/Device.h"
#include "Rendering/DeviceContext.h"
#include "Rendering/DepthStencilView.h"
#include "Rendering/Texture2D.h"

HRESULT 
RenderTargetView::init(Device& device, Texture& backBuffer, DXGI_FORMAT Format) {
  if (!device.getDevice()) {
    ERROR("RenderTargetView", "init", "Device is nullptr.");
    return E_POINTER;
  }

  if (!backBuffer.GetTextureAddress()) {
    ERROR("RenderTargetView", "init", "Texture is nullptr.");
    return E_POINTER;
  }

  if (Format == DXGI_FORMAT_UNKNOWN) {
    ERROR("RenderTargetView", "init", "Format is DXGI_FORMAT_UNKNOWN.");
    return E_INVALIDARG;
  }

  // Config the description for the render target view
  D3D11_RENDER_TARGET_VIEW_DESC desc;
  memset(&desc, 0, sizeof(desc));
  desc.Format = Format;
  desc.ViewDimension = D3D11_RTV_DIMENSION_TEXTURE2D;

  // Create the render target view
  HRESULT hr = device.CreateRenderTargetView(backBuffer.GetTexture(),
    &desc,
    &m_renderTargetView);

  if (FAILED(hr)) {
    ERROR("RenderTargetView", "init",
      ("Failed to create render target view. HRESULT: " + std::to_string(hr)).c_str());
    return hr;
  }
  return E_NOTIMPL;
}
