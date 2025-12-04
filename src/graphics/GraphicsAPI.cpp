#include "graphics/GraphicsAPI.h"
#include "graphics/ShaderProgram.h"
#include "render/Material.h"
#include <iostream>
#include <memory>

namespace Orbis
{

std::shared_ptr<ShaderProgram> GraphicsAPI::CreateShaderProgram(
    const std::string &vertexSource, const std::string &fragmentSource
)
{
    GLint success;
    char infolog[512];

    GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
    const char *vertexShaderCStr = vertexSource.c_str();
    glShaderSource(vertexShader, 1, &vertexShaderCStr, nullptr);
    glCompileShader(vertexShader);
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(vertexShader, 512, nullptr, infolog);
        std::cerr << "ERROR::SHADER::VERTEX::COMPILATION_FAILED: " << infolog << std::endl;
    }

    GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    const char *fragmentShaderCStr = fragmentSource.c_str();
    glShaderSource(fragmentShader, 1, &fragmentShaderCStr, nullptr);
    glCompileShader(fragmentShader);
    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(fragmentShader, 512, nullptr, infolog);
        std::cerr << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED: " << infolog << std::endl;
    }

    GLuint program = glCreateProgram();
    glAttachShader(program, vertexShader);
    glAttachShader(program, fragmentShader);
    glLinkProgram(program);
    glGetProgramiv(program, GL_LINK_STATUS, &success);
    if (!success)
    {
        glGetProgramInfoLog(program, 512, nullptr, infolog);
        std::cerr << "ERROR::SHADER::PROGRAM::LINK_FAILED: " << infolog << std::endl;
        return nullptr;
    }

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

    return std::make_shared<ShaderProgram>(program);
}

void GraphicsAPI::BindShaderProgram(ShaderProgram *shaderProgram)
{
    if (shaderProgram)
    {
        shaderProgram->Bind();
    }
}

void GraphicsAPI::BindMaterial(Material *material)
{
    if (material)
    {
        material->Bind();
    }
}

} // namespace Orbis