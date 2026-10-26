#pragma once
#include "Engine/Prerequisites.h"

class DeviceContext
{
public:
	DeviceContext() = default;
	~DeviceContext();

  /**
   * @brief Initializes the DeviceContext with the provided ID3D11DeviceContext.
   * 
   * @param deviceContext A pointer to the ID3D11DeviceContext to be managed by this class.
	 */
  void 
  destroy();

  ID3D11DeviceContext*
  getDeviceContext() const noexcept
  {
    return m_deviceContext;
  }

  ID3D11DeviceContext**
  getDeviceContextAdress() noexcept
  {
    return &m_deviceContext;
  }

  /**
   * @brief Requires the underlying ID3D11DeviceContext.
	 * @return A reference to the underlying ID3D11DeviceContext.
   */ 
	ID3D11DeviceContext& 
  requireContext() const noexcept;

  /**
   * @brief Sets the viewports for the rasterizer stage.
   * 
   * @param NumViewports The number of viewports to set.
   * @param pViewports A pointer to an array of D3D11_VIEWPORT structures that describe the viewports.
   */
  void 
  RSSetViewports(unsigned int NumViewports,
                 const D3D11_VIEWPORT* pViewports) noexcept;

  /**
   * @brief Sets the shader resources for the pixel-shader stage.
   * 
   * @param StartSlot The first slot to set.
   * @param NumViews The number of shader resource views to set.
   * @param ppShaderResourceView A pointer to an array of shader resource view pointers.
   */
  void 
  PSSetShaderResources(unsigned int StartSlot, 
                       unsigned int NumViews, 
                       ID3D11ShaderResourceView* const* ppShaderResourceViews);

  /**
   * @brief Sets the render targets for the output-merger stage.
   * 
   * @param NumViews The number of render target views to set.
   * @param ppRenderTargetViews A pointer to an array of ID3D11RenderTargetView pointers that represent the render target views.
   * @param pDepthStencilView A pointer to an ID3D11DepthStencilView that represents the depth stencil view (can be nullptr).
   */
  void 
  OMSetRenderTargets(unsigned int NumViews,
                     ID3D11RenderTargetView* const* ppRenderTargetViews,
                     ID3D11DepthStencilView* pDepthStencilView) noexcept;

  /**
   * @brief Clears the specified render target view with the given color.
   * 
   * @param pRenderTargetView A pointer to the ID3D11RenderTargetView to clear.
   * @param ColorRGBA An array of four FLOAT values representing the RGBA color to clear with.
	 */
  void 
  ClearRenderTargetView(ID3D11RenderTargetView* pRenderTargetView, 
                        const float ColorRGBA[4]) noexcept;
  
  /**
   * @brief Clears the specified depth stencil view with the given depth and stencil values.
   * 
   * @param pDepthStencilView A pointer to the ID3D11DepthStencilView to clear.
   * @param ClearFlags A combination of D3D11_CLEAR_FLAG values that specify which parts of the depth stencil view to clear.
   * @param Depth A FLOAT value that specifies the depth value to clear the depth buffer to.
   * @param Stencil An unsigned int value that specifies the stencil value to clear the stencil buffer to.
   */
  void 
  ClearDepthStencilView(ID3D11DepthStencilView* pDepthStencilView, 
                        UINT ClearFlags,
                        float Depth,
                        unsigned int Stencil) noexcept;

  /**
   * @brief Updates a subresource with new data.
   * 
   * @param pDstResource A pointer to the ID3D11Resource to update.
   * @param DstSubresource The index of the destination subresource.
   * @param pDstBox A pointer to a D3D11_BOX that defines the portion of the destination subresource to update (can be nullptr).
   * @param pSrcData A pointer to the source data.
   * @param SrcRowPitch The row pitch of the source data.
   * @param SrcDepthPitch The depth pitch of the source data.
   */
  void
  UpdateSubresource(ID3D11Resource* pDstResource,
                    unsigned int DstSubresource,
                    const D3D11_BOX* pDstBox,
                    const void* pSrcData,
                    unsigned int SrcRowPitch,
                    unsigned int SrcDepthPitch) noexcept;

  /**
   * @brief Sets the vertex buffers for the input-assembler stage.
   * 
   * @param StartSlot The first input slot for binding.
   * @param NumBuffers The number of vertex buffers to set.
   * @param ppVertexBuffers A pointer to an array of ID3D11Buffer pointers that represent the vertex buffers.
   * @param pStrides A pointer to an array of unsigned int values that specify the stride (size) of each vertex buffer.
   * @param pOffsets A pointer to an array of unsigned int values that specify the offset (in bytes) from the start of each vertex buffer.
	 */
  void
  IASetVertexBuffers(unsigned int StartSlot,
                     unsigned int NumBuffers,
                     ID3D11Buffer* const* ppVertexBuffers,
                     const unsigned int* pStrides,
                     const unsigned int* pOffsets) noexcept;

  /**
   * @brief Sets the index buffer for the input-assembler stage.
   * 
   * @param pIndexBuffer A pointer to the ID3D11Buffer that represents the index buffer.
   * @param Format The format of the index data (e.g., DXGI_FORMAT_R16_UINT or DXGI_FORMAT_R32_UINT).
   * @param Offset The offset (in bytes) from the start of the index buffer to the first index to use.
	 */
  void
  IASetIndexBuffer(ID3D11Buffer* pIndexBuffer,
                   DXGI_FORMAT Format,
                   unsigned int Offset) noexcept;
  
  /**
   * @brief Sets the input layout for the input-assembler stage.
   * 
   * @param pInputLayout A pointer to the ID3D11InputLayout that represents the input layout.
	 */
  void 
  IASetInputLayout(ID3D11InputLayout* pInputLayout) noexcept;

  /**
   * @brief Sets the primitive topology for the input-assembler stage.
   * 
   * @param Topology The primitive topology to set (e.g., D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST).
	 */
  void 
  IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY Topology) noexcept;

  /**
   * @brief Sets the rasterizer state for the rasterizer stage.
   * 
   * @param pRasterizerState A pointer to the ID3D11RasterizerState that represents the rasterizer state.
	 */
  void
  RSSetState(ID3D11RasterizerState* pRasterizerState) noexcept;

  /**
   * @brief Sets the vertex shader for the vertex shader stage.
   * 
   * @param pVertexShader A pointer to the ID3D11VertexShader that represents the vertex shader.
   * @param ppClassInstances A pointer to an array of ID3D11ClassInstance pointers for class linkage (can be nullptr).
   * @param NumClassInstances The number of class instances in the ppClassInstances array.
	 */
  void
  VSSetShader(ID3D11VertexShader* pVertexShader,
              ID3D11ClassInstance* const* ppClassInstances,
              unsigned int NumClassInstances) noexcept;

  /**
   * @brief Sets the constant buffers for the vertex shader stage.
   * 
   * @param StartSlot The first input slot for binding.
   * @param NumBuffers The number of constant buffers to set.
   * @param ppConstantBuffers A pointer to an array of ID3D11Buffer pointers that represent the constant buffers.
	 */
  void
  VSSetConstantBuffers(unsigned int StartSlot,
                       unsigned int NumBuffers,
                       ID3D11Buffer* const* ppConstantBuffers) noexcept;

  /**
   * @brief Sets the pixel shader for the pixel shader stage.
   * 
   * @param pPixelShader A pointer to the ID3D11PixelShader that represents the pixel shader.
   * @param ppClassInstances A pointer to an array of ID3D11ClassInstance pointers for class linkage (can be nullptr).
   * @param NumClassInstances The number of class instances in the ppClassInstances array.
	 */
  void
  PSSetShader(ID3D11PixelShader* pPixelShader, 
              ID3D11ClassInstance* const* ppClassInstances, 
              unsigned int NumClassInstances) noexcept;

	/**
	 * @brief Sets the shader resources for the pixel shader stage.
   * 
	 * @param StartSlot The first input slot for binding.
	 * @param NumViews The number of shader resource views to set.
	 * @param ppShaderResourceViews A pointer to an array of ID3D11ShaderResourceView pointers that represent the shader resource views.
   */
  void 
  DrawIndexed(unsigned int IndexCount,
              unsigned int StartIndexLocation,
              int BaseVertexLocation) noexcept;
private:
  ID3D11DeviceContext* m_deviceContext = nullptr;

};
