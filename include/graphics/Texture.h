#pragma once

#include_next <GL/glew.h>

namespace Geni
{

class Texture
{
  public:
    Texture(int width, int height, int numChannels, unsigned char *data);
    ~Texture();
    GLuint GetID() const;

  private:
    GLuint m_ID = 0;
    int m_width = 0;
    int m_height = 0;
    int m_numChannels = 0;
};

} // namespace Geni