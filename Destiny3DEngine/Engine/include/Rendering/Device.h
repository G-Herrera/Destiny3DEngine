#pragma once
#include "Engine/Prerequisites.h"

class Device
{
public:
  Device() = default;
  ~Device();

  void 
  init();

	void 
  destroy();

  ID3D11Device* 
  getDevice() { return m_device; }

  /**
	 * @brief Creates a render target view for the specified resource.
   * 
   * @param pResource The resource for which to create the render target view.
   * @param pDesc A pointer to a D3D11_RENDER_TARGET_VIEW_DESC structure that describes the render target view.
   * @param ppRTView A pointer to a variable that receives the created render target view.
   * @return HRESULT Indicates success or failure.
   */
  HRESULT 
  CreateRenderTargetView(ID3D11Resource* pResource, 
                         const D3D11_RENDER_TARGET_VIEW_DESC* pDesc,
                         ID3D11RenderTargetView** ppRTView);

  /**
   * @brief Creates a 2D texture resource.
   * 
   * @param pDesc A pointer to a D3D11_TEXTURE2D_DESC structure that describes the texture.
   * @param pInitialData A pointer to an array of D3D11_SUBRESOURCE_DATA structures that describe the initial data for the texture.
   * @param ppTexture2D A pointer to a variable that receives the created texture.
   * @return HRESULT Indicates success or failure.
	 */
  HRESULT
  CreateTexture2D(const D3D11_TEXTURE2D_DESC* pDesc,
                  const D3D11_SUBRESOURCE_DATA* pInitialData,
                  ID3D11Texture2D** ppTexture2D);

  /**
   * @brief Creates a depth stencil view for the specified resource.
   * 
   * @param pResource The resource for which to create the depth stencil view.
   * @param pDesc A pointer to a D3D11_DEPTH_STENCIL_VIEW_DESC structure that describes the depth stencil view.
   * @param ppDepthStencilView A pointer to a variable that receives the created depth stencil view.
   * @return HRESULT Indicates success or failure.
	 */
  HRESULT
  CreateDepthStencilView(ID3D11Resource* pResource,
                         const D3D11_DEPTH_STENCIL_VIEW_DESC* pDesc,
                         ID3D11DepthStencilView** ppDepthStencilView);
  
  /**
   * @brief Creates a buffer resource.
   * 
   * @param pDesc A pointer to a D3D11_BUFFER_DESC structure that describes the buffer.
   * @param pInitialData A pointer to a D3D11_SUBRESOURCE_DATA structure that describes the initial data for the buffer.
   * @param ppBuffer A pointer to a variable that receives the created buffer.
   * @return HRESULT Indicates success or failure.
	 */
  HRESULT
  CreateVertexShader(const void* pShaderBytecode, 
                     SIZE_T BytecodeLength, 
                     ID3D11ClassLinkage* pClassLinkage,
                     ID3D11VertexShader** ppVertexShader);

  /**
   * @brief Creates an input layout object to describe the input-buffer data for the input-assembler stage.
   * 
   * @param pInputElementDescs A pointer to an array of D3D11_INPUT_ELEMENT_DESC structures that describe the input data.
   * @param NumElements The number of elements in the pInputElementDescs array.
   * @param pShaderBytecodeWithInputSignature A pointer to the compiled shader bytecode that contains the input signature.
   * @param BytecodeLength The size of the compiled shader bytecode in bytes.
   * @param ppInputLayout A pointer to a variable that receives the created input layout object.
   * @return HRESULT Indicates success or failure.
	 */
  HRESULT 
  CreateInputLayout(const D3D11_INPUT_ELEMENT_DESC* pInputElementDescs,
                    UINT NumElements,
                    const void* pShaderBytecodeWithInputSignature,
                    SIZE_T BytecodeLength,
                    ID3D11InputLayout** ppInputLayout);
  /**
   * @brief Creates a buffer resource.
   * 
   * @param pDesc A pointer to a D3D11_BUFFER_DESC structure that describes the buffer.
   * @param pInitialData A pointer to a D3D11_SUBRESOURCE_DATA structure that describes the initial data for the buffer.
   * @param ppBuffer A pointer to a variable that receives the created buffer.
   * @return HRESULT Indicates success or failure.
	 */
  HRESULT
  CreateBuffer(const D3D11_BUFFER_DESC* pDesc,
               const D3D11_SUBRESOURCE_DATA* pInitialData,
               ID3D11Buffer** ppBuffer);


  /**
   * @brief Creates a pixel shader object.
   * 
   * @param pShaderBytecode A pointer to the compiled shader bytecode.
   * @param BytecodeLength The size of the compiled shader bytecode in bytes.
   * @param pClassLinkage A pointer to an ID3D11ClassLinkage interface for class linkage (can be nullptr).
   * @param ppPixelShader A pointer to a variable that receives the created pixel shader object.
   * @return HRESULT Indicates success or failure.
	 */
  HRESULT
  CreatePixelShader(const void* pShaderBytecode, 
                    SIZE_T BytecodeLength,
                    ID3D11ClassLinkage* pClassLinkage, 
                    ID3D11PixelShader** ppPixelShader);
  /**
   * @brief Creates a rasterizer state object.
   * 
   * @param pRasterizerDesc A pointer to a D3D11_RASTERIZER_DESC structure that describes the rasterizer state.
   * @param ppRasterizerState A pointer to a variable that receives the created rasterizer state object.
   * @return HRESULT Indicates success or failure.
	 */
  HRESULT
  CreateRasterizerState(const D3D11_RASTERIZER_DESC* pRasterizerDesc,
                        ID3D11RasterizerState** ppRasterizerState);



  D3D_FEATURE_LEVEL 
  getFeatureLevel() { return featureLevel; }

private:
  ID3D11Device* m_device = nullptr;
  D3D_FEATURE_LEVEL featureLevel = D3D_FEATURE_LEVEL_11_0;
};