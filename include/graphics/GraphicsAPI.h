#pragma once
#include <memory>
#include <string>

namespace Orbis
{

class ShaderProgram;

class GraphicsAPI
{
  public:
    std::shared_ptr<ShaderProgram> CreateShaderProgram(
        const std::string &vertexSource, const std::string &fragmentSource
    );
    void BindShaderProgram(ShaderProgram *shaderProgram);
};

} // namespace Orbis