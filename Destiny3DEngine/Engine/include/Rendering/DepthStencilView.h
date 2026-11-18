#pragma once
#include "Engine/Prerequisites.h"

class Device;
class DeviceContext;
class Texture;

class 
DepthStencilView {
public:
  DepthStencilView()  = default;
  ~DepthStencilView() = default;
  
  /**
   * @brief Initializes the DepthStencilView with a device, depth stencil buffer texture, and format.
   * 
   * @param device The Direct3D device used for rendering.
   * @param depthStencilBuffer The depth stencil buffer texture to be used for depth testing.
   * @param Format The format of the depth stencil view.
   * @return HRESULT indicating success or failure.
	 */
  HRESULT 
  init(Device& device, Texture& depthStencilBuffer, DXGI_FORMAT Format);
  
  /**
   * @brief Initializes the DepthStencilView with a device, depth stencil buffer texture, view dimension, and format.
   * 
   * @param device The Direct3D device used for rendering.
   * @param depthStencil The depth stencil buffer texture to be used for depth testing.
   * @param Format The format of the depth stencil view.
   * @param ViewDimension The view dimension of the depth stencil view.
   * @return HRESULT indicating success or failure.
	 */
  HRESULT 
  init(Device& device, 
       Texture& depthStencil, 
       DXGI_FORMAT Format,
       D3D11_DSV_DIMENSION ViewDimension);
  
  /**
   * @brief Updates the depth stencil view. This function can be used to perform any necessary updates before rendering.
	 */
  void 
  update();
  
  /**
   * @brief Renders the scene using the specified device context.
   * 
   * @param deviceContext The device context used for rendering.
	 */
  void 
  render(DeviceContext& deviceContext);

  /**
   * @brief Destroys the depth stencil view and releases associated resources.
	 */
  void 
  destroy();

  /**
   * @brief Retrieves the underlying ID3D11DepthStencilView pointer.
   * 
   * @return Pointer to the ID3D11DepthStencilView interface.
	 */
	ID3D11DepthStencilView* getDepthStencilView() const { return m_DepthStencilView; }
private:
	ID3D11DepthStencilView* m_DepthStencilView = nullptr; ///> Pointer to the Direct3D depth stencil view interface.
};