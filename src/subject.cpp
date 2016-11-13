#include "subject.h"

void Subject::Attach(Observer* const & o)
{
  auto it = std::find(m_observers.begin(), m_observers.end(), o);
  if (it == m_observers.end())
    m_observers.push_back(o);
}

void Subject::Detach(Observer* const & o)
{
  auto it = std::find(m_observers.begin(), m_observers.end(), o);
  if (it != m_observers.end())
    m_observers.remove(o);
}

void Subject::Notify(EventHandler const & event, Box2D box)
{
  for(auto it = m_observers.begin(); it != m_observers.end(); ++it)
  {
    (*it)->UpdateEvent(event, box);
  }
}
