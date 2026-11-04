#pragma once
#include "Engine/Prerequisites.h"

/**
 * @brief Represents a mesh component that holds vertex and index data for rendering.
 */
class 
MeshComponent {
public:
	MeshComponent() : m_numVertex(0), m_numIndex(0) {}
	~MeshComponent()=default;

public:
	std::string m_name;///> The name of the mesh component.

	/**
	 * @brief The local transformation matrix of the mesh component.
	 * 
	 * This matrix represents the position, rotation, and scale of the mesh in its local space.
	 * It is initialized to the identity matrix.
	 */
	DirectX::XMFLOAT4X4 m_localTransform = DirectX::XMFLOAT4X4(
		1.0f, 0.0f, 0.0f, 0.0f,
		0.0f, 1.0f, 0.0f, 0.0f,
		0.0f, 0.0f, 1.0f, 0.0f,
		0.0f, 0.0f, 0.0f, 1.0f);

	std::vector<Vertex> m_vertex;///> A vector that holds the vertex data for the mesh.
	std::vector<unsigned int> m_index;///> A vector that holds the index data for the mesh.
	int m_numVertex;///> The number of vertices in the mesh.
	int m_numIndex;///> The number of indices in the mesh.

private:

};