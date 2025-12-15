#include "core/Application.h"

namespace Geni
{

void Application::SetNeedsToBeClosed(bool value)
{
    m_needsToBeClosed = value;
}

bool Application::NeedsToBeClosed() const
{
    return m_needsToBeClosed;
}

} // namespace Geni
