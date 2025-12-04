#include "scene/Component.h"
#include <cstddef>

namespace Orbis
{

size_t Component::nextID = 1;

GameObject *Component::GetOwner()
{
    return m_owner;
}

} // namespace Orbis