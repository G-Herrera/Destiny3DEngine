#include "Rendering/Device.h"

HRESULT 
Device::CreateRenderTargetView(ID3D11Resource* pResource, 
                               const D3D11_RENDER_TARGET_VIEW_DESC* pDesc, 
                               ID3D11RenderTargetView** ppRTView) {
  if (ppRTView == nullptr) {
    ERROR("Device", "CreateRenderTargetView", "Output pointer is null.");
		return E_POINTER;
  }

	*ppRTView = nullptr; // Initialize the output pointer to nullptr

  if (m_device == nullptr || pResource == nullptr) {
    ERROR("Device", "CreateRenderTargetView", "Device or resource is null.");
		return E_INVALIDARG; // Return an error code if the device or resource is not valid
  }
  
  HRESULT result = m_device->CreateRenderTargetView(pResource, pDesc, ppRTView);

  if (FAILED(result)) {
    ERROR("Device", 
          "CreateRenderTargetView",
          ("Failed to create render target view. HRESULT: " + std::to_string(result)).c_str());
    return result;
  }

  MESSAGE("Device", "CreateRenderTargetView", "Creating render target view.");
  return result;
}

HRESULT
Device::CreateTexture2D(const D3D11_TEXTURE2D_DESC* pDesc,
                        const D3D11_SUBRESOURCE_DATA* pInitialData,
                        ID3D11Texture2D** ppTexture2D)
{
  if (ppTexture2D == nullptr) {
    ERROR("Device", "CreateTexture2D", "Output pointer is null.");
    return E_POINTER;
  }
  
  *ppTexture2D = nullptr;
  
  if (m_device == nullptr || pDesc == nullptr) {
    ERROR("Device", "CreateTexture2D", "Device or description is null.");
    return E_INVALIDARG;
  }
  
  HRESULT result = m_device->CreateTexture2D(pDesc,
                                             pInitialData,
                                             ppTexture2D);
  
  if (FAILED(result)) {
    ERROR("Device",
          "CreateTexture2D",
          ("Failed to create texture 2D. HRESULT: " + std::to_string(result)).c_str());
  
    return result;
  }
  
  MESSAGE("Device", "CreateTexture2D", "Creating texture 2D.");
  
  return result;
}

HRESULT
Device::CreateDepthStencilView(ID3D11Resource* pResource,
                               const D3D11_DEPTH_STENCIL_VIEW_DESC* pDesc,
                               ID3D11DepthStencilView** ppDepthStencilView)
{
  if (ppDepthStencilView == nullptr) {
    ERROR("Device", "CreateDepthStencilView", "Output pointer is null.");
    return E_POINTER;
  }

  *ppDepthStencilView = nullptr;

  if (m_device == nullptr || pResource == nullptr) {
    ERROR("Device", "CreateDepthStencilView", "Device or resource is null.");

    return E_INVALIDARG;
  }

  HRESULT result = m_device->CreateDepthStencilView(pResource,
                                                    pDesc,
                                                    ppDepthStencilView);

  if (FAILED(result)) {
    ERROR("Device",
          "CreateDepthStencilView",
          ("Failed to create depth stencil view. HRESULT: " + std::to_string(result)).c_str());

    return result;
  }

  MESSAGE("Device", "CreateDepthStencilView", "Creating depth stencil view.");

  return result;
}

HRESULT
Device::CreateVertexShader(const void* pShaderBytecode,
                           SIZE_T BytecodeLength,
                           ID3D11ClassLinkage* pClassLinkage,
                           ID3D11VertexShader** ppVertexShader)
{
  if (ppVertexShader == nullptr) {
    ERROR("Device", "CreateVertexShader", "Output pointer is null.");
    return E_POINTER;
  }

  *ppVertexShader = nullptr;

  if (m_device == nullptr || pShaderBytecode == nullptr) {
    ERROR("Device",
          "CreateVertexShader",
          "Device or shader bytecode is null.");

    return E_INVALIDARG;
  }

  HRESULT result = m_device->CreateVertexShader(pShaderBytecode,
                                                BytecodeLength,
                                                pClassLinkage,
                                                ppVertexShader);

  if (FAILED(result)) {
    ERROR("Device",
          "CreateVertexShader",
          ("Failed to create vertex shader. HRESULT: " + std::to_string(result)).c_str());

    return result;
  }

  MESSAGE("Device", "CreateVertexShader", "Creating vertex shader.");

  return result;
}

HRESULT
Device::CreateInputLayout(const D3D11_INPUT_ELEMENT_DESC* pInputElementDescs,
                          UINT NumElements,
                          const void* pShaderBytecodeWithInputSignature,
                          SIZE_T BytecodeLength,
                          ID3D11InputLayout** ppInputLayout)
{
  if (ppInputLayout == nullptr) {
    ERROR("Device", "CreateInputLayout", "Output pointer is null.");
    return E_POINTER;
  }

  *ppInputLayout = nullptr;

  if (m_device == nullptr ||
    pInputElementDescs == nullptr ||
    pShaderBytecodeWithInputSignature == nullptr)
  {
    ERROR("Device",
          "CreateInputLayout",
          "Device, input description or shader bytecode is null.");

    return E_INVALIDARG;
  }

  HRESULT result = m_device->CreateInputLayout(pInputElementDescs,
                                               NumElements,
                                               pShaderBytecodeWithInputSignature,
                                               BytecodeLength,
                                               ppInputLayout);

  if (FAILED(result)) {
    ERROR("Device",
          "CreateInputLayout",
          ("Failed to create input layout. HRESULT: " + std::to_string(result)).c_str());

    return result;
  }

  MESSAGE("Device", "CreateInputLayout", "Creating input layout.");

  return result;
}


HRESULT
Device::CreateBuffer(const D3D11_BUFFER_DESC* pDesc,
                     const D3D11_SUBRESOURCE_DATA* pInitialData,
                     ID3D11Buffer** ppBuffer)
{
  if (ppBuffer == nullptr) {
    ERROR("Device", "CreateBuffer", "Output pointer is null.");
    return E_POINTER;
  }

  *ppBuffer = nullptr;

  if (m_device == nullptr || pDesc == nullptr) {
    ERROR("Device", "CreateBuffer", "Device or description is null.");

    return E_INVALIDARG;
  }

  HRESULT result = m_device->CreateBuffer(pDesc, pInitialData, ppBuffer);

  if (FAILED(result)) {
    ERROR("Device",
          "CreateBuffer",
          ("Failed to create buffer. HRESULT: " + std::to_string(result)).c_str());

    return result;
  }

  MESSAGE("Device", "CreateBuffer", "Creating buffer.");

  return result;
}

HRESULT
Device::CreatePixelShader(const void* pShaderBytecode,
                          SIZE_T BytecodeLength,
                          ID3D11ClassLinkage* pClassLinkage,
                          ID3D11PixelShader** ppPixelShader)
{
  if (ppPixelShader == nullptr) {
    ERROR("Device", "CreatePixelShader", "Output pointer is null.");
    return E_POINTER;
  }

  *ppPixelShader = nullptr;

  if (m_device == nullptr || pShaderBytecode == nullptr) {
    ERROR("Device", "CreatePixelShader", "Device or shader bytecode is null.");

    return E_INVALIDARG;
  }

  HRESULT result = m_device->CreatePixelShader(pShaderBytecode,
                                               BytecodeLength,
                                               pClassLinkage,
                                               ppPixelShader);

  if (FAILED(result)) {
    ERROR("Device",
          "CreatePixelShader",
          ("Failed to create pixel shader. HRESULT: " + std::to_string(result)).c_str());

    return result;
  }

  MESSAGE("Device", "CreatePixelShader", "Creating pixel shader.");

  return result;
}

HRESULT
Device::CreateRasterizerState(const D3D11_RASTERIZER_DESC* pRasterizerDesc,
                              ID3D11RasterizerState** ppRasterizerState)
{
  if (ppRasterizerState == nullptr) {
    ERROR("Device", "CreateRasterizerState", "Output pointer is null.");

    return E_POINTER;
  }

  *ppRasterizerState = nullptr;

  if (m_device == nullptr || pRasterizerDesc == nullptr) {
    ERROR("Device", "CreateRasterizerState", "Device or description is null.");

    return E_INVALIDARG;
  }

  HRESULT result = m_device->CreateRasterizerState(pRasterizerDesc, ppRasterizerState);

  if (FAILED(result)) {
    ERROR("Device", 
          "CreateRasterizerState",
          ("Failed to create rasterizer state. HRESULT: " + std::to_string(result)).c_str());

    return result;
  }

  MESSAGE("Device", "CreateRasterizerState", "Creating rasterizer state.");

  return result;
}


