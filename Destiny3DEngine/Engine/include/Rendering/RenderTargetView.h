#pragma once
#include "Engine/Prerequisites.h"

class Device;
class DeviceContext;
class Texture2D;
class DepthStencilView;

class
RenderTargetView {
public:
  RenderTargetView()  = default;
  ~RenderTargetView() = default;
  /**
	 * @brief Initializes the RenderTargetView with a device, back buffer texture, and format.
   * 
	 * @param device The Direct3D device used for rendering.
   * @param backBuffer The back buffer texture to be used as the render target.
   * @param Format The format of the render target view.
   * @return HRESULT indicating success or failure.
   */
  HRESULT 
  init(Device& device, Texture2D& backBuffer, DXGI_FORMAT Format);
  
	/**
   *
	 * @brief Initializes the RenderTargetView with a device, input texture, view dimension, and format.
   * 
   * @param device The Direct3D device used for rendering.
   * @param inTex The input texture to be used as the render target.
   * @param ViewDimension The view dimension of the render target view.
   * @param Format The format of the render target view.
   * @return HRESULT indicating success or failure.
   */ 
  HRESULT 
  init(Device& device, 
       Texture2D& inTex, 
       D3D11_RTV_DIMENSION ViewDimension, 
       DXGI_FORMAT Format);

  /**
   * @brief Updates the render target view. This function can be used to perform any necessary updates before rendering.
	 */
  void 
  update();

  /**
   * @brief Renders the scene using the specified device context, depth stencil view, number of views, and clear color.
   * 
   * @param deviceContext The device context used for rendering.
   * @param depthStencilView The depth stencil view used for depth testing.
   * @param numViews The number of views to render.
   * @param ClearColor The color used to clear the render target view.
	 */
  void 
  render(DeviceContext& deviceContext,
         DepthStencilView& depthStencilView,
         unsigned int numViews,
         const float ClearColor[4]);

  /**
   * @brief Renders the scene using the specified device context and number of views.
   * 
   * @param deviceContext The device context used for rendering.
   * @param numViews The number of views to render.
	 */
  void 
  render(DeviceContext& deviceContext, unsigned int numViews);

  /**
   * @brief Destroys the render target view and releases any associated resources.
	 */
  void
  destroy();

  /**
   * @brief Retrieves the underlying ID3D11RenderTargetView pointer.
   * 
   * @return ID3D11RenderTargetView* The pointer to the Direct3D render target view.
	 */
  ID3D11RenderTargetView* 
  getRenderTargetView() const {return m_renderTargetView;}

private:
	ID3D11RenderTargetView* m_renderTargetView = nullptr; ///> Pointer to the Direct3D render target view.

};