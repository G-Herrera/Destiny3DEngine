#include "Rendering/DepthStencilView.h"
#include "Rendering/Device.h"
#include "Rendering/DeviceContext.h"
#include "Rendering/Texture2D.h"

HRESULT
DepthStencilView::init(Device& device, Texture2D& depthStencil, DXGI_FORMAT format) {
  if (!device.getDevice()) {
    ERROR("DepthStencilView", "init", "Device is null.");
  }

  if (!depthStencil.GetTextureAddress()) {
    ERROR("DepthStencilView", "init", "Texture is null.");
    return E_FAIL;
  }

  // Config depth stencil view description
  D3D11_DEPTH_STENCIL_VIEW_DESC descDSV;
  memset(&descDSV, 0, sizeof(descDSV));
  descDSV.Format = format;
  descDSV.ViewDimension = D3D11_DSV_DIMENSION_TEXTURE2DMS;
  descDSV.Texture2D.MipSlice = 0;

  // Create depth stencil view
  HRESULT hr = device.CreateDepthStencilView(depthStencil.GetTexture(),
                                             &descDSV,
                                             &m_DepthStencilView);

  if (FAILED(hr)) {
    ERROR("DepthStencilView", "init",
      ("Failed to create depth stencil view. HRESULT: " + std::to_string(hr)).c_str());
    return hr;
  }

  return S_OK;
}

HRESULT 
DepthStencilView::init(Device& device, 
                       Texture2D& depthStencil, 
                       DXGI_FORMAT Format, 
                       D3D11_DSV_DIMENSION ViewDimension) {
  if (!device.getDevice()) {
    ERROR("DepthStencilView", "init", "Device is null.");
    return E_POINTER;
  }

  if (!depthStencil.GetTextureAddress()) {
    ERROR("DepthStencilView", "init", "Texture is null.");
    return E_FAIL;
  }

  D3D11_DEPTH_STENCIL_VIEW_DESC descDSV{};
  descDSV.Format = Format;
  descDSV.ViewDimension = ViewDimension;

  if (ViewDimension == D3D11_DSV_DIMENSION_TEXTURE2D) {
    descDSV.Texture2D.MipSlice = 0;
  }

  HRESULT hr = device.CreateDepthStencilView(depthStencil.GetTexture(),
                                             &descDSV,
                                             &m_DepthStencilView);

  if (FAILED(hr)) {
    ERROR("DepthStencilView", "init",
         ("Failed to create depth stencil view. HRESULT: " + std::to_string(hr)).c_str());
    return hr;
  }

  return S_OK;
}

void
DepthStencilView::render(DeviceContext& deviceContext) {
  if (!deviceContext.getDeviceContext()) {
    ERROR("DepthStencilView", "render", "Device context is null.");
    return;
  }

  // Clear depth stencil view
  deviceContext.ClearDepthStencilView(m_DepthStencilView,
                                      D3D11_CLEAR_DEPTH | D3D11_CLEAR_STENCIL,
                                      1.0f,
                                      0);
}

void
DepthStencilView::destroy() {
  SAFE_RELEASE(m_DepthStencilView);
}