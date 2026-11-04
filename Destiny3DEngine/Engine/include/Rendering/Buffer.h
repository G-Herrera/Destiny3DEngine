#pragma once
#include "Engine/Prerequisites.h"
#include "Engine/MeshComponent.h"

/**
 * @brief Represents a buffer that can be used for rendering in Direct3D 11.
 * 
 * This class encapsulates the creation, updating, and rendering of a Direct3D 11 buffer.
 */
class Device;
class DeviceContext;

class 
Buffer {
public:
	Buffer()  = default;
	~Buffer() = default;

  /**
   * @brief Initializes the buffer with the provided mesh data and bind flags.
   * 
   * @param device The Direct3D device used to create the buffer.
   * @param mesh The mesh component containing vertex and index data.
   * @param bindFlag The bind flags specifying how the buffer will be used (e.g., vertex buffer, index buffer).
   * @return HRESULT Indicates success or failure of the initialization.
	 */
	HRESULT 
  init(Device& device, const MeshComponent& mesh, unsigned int bindFlag);

  /**
   * @brief Initializes the buffer with a specified byte width.
   * 
   * @param device The Direct3D device used to create the buffer.
   * @param ByteWidth The size of the buffer in bytes.
   * @return HRESULT Indicates success or failure of the initialization.
	 */
	HRESULT 
  init(Device& device, unsigned int ByteWidth);

  /**
   * @brief Updates the buffer with new data.
   * 
   * @param deviceContext The Direct3D device context used to update the buffer.
   * @param pDstResource The destination resource to update.
   * @param DstSubresource The destination subresource index.
   * @param pDstBox A pointer to a D3D11_BOX structure that defines the portion of the destination resource to update.
   * @param pSrcData A pointer to the source data.
   * @param SrcRowPitch The row pitch of the source data.
   * @param SrcDepthPitch The depth pitch of the source data.
   */
	void 
	update(DeviceContext& deviceContext,
         ID3D11Resource* pDstResource,
         unsigned int DstSubresource,
         const D3D11_BOX* pDstBox,
         const void* pSrcData,
         unsigned int SrcRowPitch,
         unsigned int SrcDepthPitch);

  /**
   * @brief Renders the buffer by setting it to the input assembler stage.
   * 
   * @param deviceContext The Direct3D device context used for rendering.
   * @param StartSlot The starting slot for binding the buffer.
   * @param NumBuffers The number of buffers to bind.
   * @param setPixelShader A flag indicating whether to set the pixel shader (default is false).
   * @param format The format of the index buffer (default is DXGI_FORMAT_UNKNOWN).
	 */
  void 
  render(DeviceContext& deviceContext,
         unsigned int StartSlot,
         unsigned int NumBuffers,
         bool setPixelShader = false,
         DXGI_FORMAT format = DXGI_FORMAT_UNKNOWN);

  /**
   * @brief Destroys the buffer and releases associated resources.
	 */
  void 
  destroy();

  /**
   * @brief Creates the Direct3D buffer with the specified description and initial data.
   * 
   * @param device The Direct3D device used to create the buffer.
   * @param desc A reference to a D3D11_BUFFER_DESC structure that describes the buffer.
   * @param initData A pointer to a D3D11_SUBRESOURCE_DATA structure that contains the initial data for the buffer (can be nullptr).
   * @return HRESULT Indicates success or failure of the buffer creation.
	 */
  HRESULT 
  createBuffer(Device& device, D3D11_BUFFER_DESC& desc, D3D11_SUBRESOURCE_DATA* initData);

  /**
   * @brief Gets the underlying Direct3D buffer.
   * 
   * @return ID3D11Buffer* A pointer to the underlying ID3D11Buffer.
	 */
  ID3D11Buffer* getBuffer() const noexcept { return m_buffer; }
public:
  ID3D11Buffer* m_buffer = nullptr;///> The underlying Direct3D buffer.
private:
  unsigned int m_stride = 0;///> The stride of the buffer.
  unsigned int m_offset = 0;///> The offset of the buffer.
  unsigned int m_bindFlag = 0;///> The bind flags of the buffer.
};
