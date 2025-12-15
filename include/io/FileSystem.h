#pragma once

#include <filesystem>

namespace Geni
{

class FileSystem
{
  public:
    std::filesystem::path GetExecutableFolder() const;
    std::filesystem::path GetAssetsFolder() const;
};

} // namespace Geni