
#pragma once
#include "Engine/Prerequisites.h"

class Device;
class DeviceContext;

/**
 * @class RasterizerState
 * @brief Represents a Direct3D 11 rasterizer state.
 *
 * The RasterizerState class manages the rasterizer configuration used
 * during the rendering pipeline, controlling polygon filling, face
 * culling, triangle winding order, and depth clipping.
 */
class 
RasterizerState {
public:
  /**
   * @brief Default constructor.
   */
  RasterizerState() = default;

  /**
   * @brief Default destructor.
   */
  ~RasterizerState() = default;

  /**
   * @brief Initializes the rasterizer state using the specified device.
   *
   * @param device The Direct3D device used to create the rasterizer state.
   * @return HRESULT indicating whether the initialization succeeded or failed.
   */
  HRESULT 
  init(Device device);

  /**
   * @brief Initializes the rasterizer state with the specified rasterization settings.
   *
   * @param device The Direct3D device used to create the rasterizer state.
   * @param fill The polygon fill mode (solid or wireframe).
   * @param cull The face culling mode (none, front, or back).
   * @param frontCCW Specifies whether front-facing triangles use
   * counter-clockwise vertex winding.
   * @param depthClip Enables or disables depth clipping.
   * @return HRESULT indicating whether the initialization succeeded or failed.
   */
  HRESULT 
  init(Device& device,
       D3D11_FILL_MODE fill,
       D3D11_CULL_MODE cull,
       bool frontCCW,
       bool depthClip);

  /**
   * @brief Updates the rasterizer state.
   *
   * Performs any necessary operations to prepare the rasterizer state
   * for use during rendering.
   */
  void 
  update();

  /**
   * @brief Binds the rasterizer state to the rendering pipeline.
   *
   * @param deviceContext The device context used to bind the rasterizer state.
   */
  void 
  render(DeviceContext& deviceContext);

  /**
   * @brief Retrieves the underlying Direct3D 11 rasterizer state.
   *
   * @return Pointer to the ID3D11RasterizerState interface.
   */
  ID3D11RasterizerState* getRasterizerState() const { return m_rasterizerState; }

private:
  ID3D11RasterizerState* m_rasterizerState = nullptr; ///< Pointer to the Direct3D 11 rasterizer state interface.
};
