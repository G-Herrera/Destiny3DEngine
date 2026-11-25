#pragma once
#include "Engine/Prerequisites.h"
#include "Rendering/InputLayout.h"

class Device;
class DeviceContext;
class LayoutBuilder;

/**
 * @class ShaderProgram
 * @brief Gestiona la carga, inicialización y renderizado de programas Shader.
 */
class 
ShaderProgram {
public:
  /**
   * @brief Constructor por defecto de ShaderProgram.
   */
  ShaderProgram() = default;

  /**
   * @brief Destructor por defecto de ShaderProgram.
   */
  ~ShaderProgram() = default;

  /**
   * @brief Inicializa el programa Shader.
   *
   * Carga el archivo del Shader y configura su Layout correspondiente.
   *
   * @param device Referencia al dispositivo gráfico.
   * @param fileName Ruta o nombre del archivo del Shader.
   * @param layoutBuilder Objeto encargado de construir el Layout.
   * @return HRESULT Código que indica si la inicialización fue exitosa.
   */
  HRESULT 
  init(Device& device,const std::string& fileName,LayoutBuilder layoutBuilder);

  /**
   * @brief Actualiza el estado del programa Shader.
   */
  void 
  update();

  /**
   * @brief Ejecuta el renderizado utilizando el programa Shader.
   *
   * @param deviceContext Contexto del dispositivo gráfico.
   */
  void 
  render(DeviceContext& deviceContext);

  /**
   * @brief Ejecuta el renderizado utilizando un tipo específico de Shader.
   *
   * @param deviceContext Contexto del dispositivo gráfico.
   * @param type Tipo de Shader que se utilizará durante el renderizado.
   */
  void 
  render(DeviceContext& deviceContext, ShaderType type);

  /**
   * @brief Crea un Input Layout para la configuración de los vértices.
   *
   * @param device Referencia al dispositivo gráfico utilizado para crear
   *               el Input Layout.
   * @param layoutBuilder Constructor que contiene la descripción de los
   *                       elementos del Input Layout.
   *
   * @return HRESULT Código que indica si la operación se realizó correctamente.
   */
  HRESULT 
  CreateInputLayout(Device& device, LayoutBuilder);

  /**
   * @brief Crea un Shader del tipo especificado.
   *
   * @param device Referencia al dispositivo gráfico utilizado para crear
   *               el Shader.
   * @param type Tipo de Shader que se desea crear.
   *
   * @return HRESULT Código que indica si la operación se realizó correctamente.
   */
  HRESULT 
  CreateShader(Device& device, ShaderType type);

  /**
   * @brief Crea un Shader a partir de un archivo especificado.
   *
   * @param device Referencia al dispositivo gráfico utilizado para crear
   *               el Shader.
   * @param type Tipo de Shader que se desea crear.
   * @param fileName Ruta o nombre del archivo que contiene el código
   *                 del Shader.
   *
   * @return HRESULT Código que indica si la operación se realizó correctamente.
   */
  HRESULT 
  CreateShader(Device& device, ShaderType type, const std::string& fileName);

  /**
   * @brief Compila un Shader a partir de un archivo.
   *
   * @param szFileName Nombre o ruta del archivo que contiene el código
   *                   fuente del Shader.
   * @param szEntryPoint Nombre de la función de entrada del Shader
   *                     que se desea compilar.
   * @param szShaderModel Modelo de Shader que se utilizará durante
   *                      la compilación.
   * @param ppBlobOut Puntero doble donde se almacena el blob de salida
   *                  generado por el compilador.
   *
   * @return HRESULT Código que indica si la compilación se realizó
   *                 correctamente.
   */
  HRESULT 
  CompileShaderFromFile(char* szFileName,
                        LPCSTR szEntryPoint,
                        LPCSTR szShaderModel,
                        ID3DBlob** ppBlobOut);
public:
  /**
   * @brief Puntero al objeto Vertex Shader de Direct3D 11.
   *
   * Se encarga de almacenar el shader de vértices utilizado
   * durante el proceso de renderizado.
   */
  ID3D11VertexShader* m_VertexShader = nullptr;
  
  /**
   * @brief Puntero al objeto Pixel Shader de Direct3D 11.
   *
   * Almacena el shader de píxeles encargado de procesar
   * la información de los píxeles durante el renderizado.
   */
  ID3D11PixelShader* m_PixelShader = nullptr;
  
  /**
   * @brief Estructura que almacena la descripción del Input Layout.
   *
   * Define cómo se organiza e interpreta la información
   * de entrada que recibe el Vertex Shader.
   */
  InputLayout m_inputLayout;
  
private:
  /**
   * @brief Nombre o ruta del archivo del shader.
   *
   * Almacena la cadena de texto correspondiente al archivo
   * desde el cual se carga el shader.
   */
  std::string m_shaderFileName;

  /**
   * @brief Puntero al buffer de datos del Vertex Shader.
   *
   * Almacena el código compilado del Vertex Shader
   * mediante un objeto ID3DBlob.
   */
  ID3DBlob* m_vertexShaderData = nullptr;

  /**
   * @brief Puntero al buffer de datos del Pixel Shader.
   *
   * Almacena el código compilado del Pixel Shader
   * mediante un objeto ID3DBlob.
   */
  ID3DBlob* m_pixelShaderData = nullptr;
};