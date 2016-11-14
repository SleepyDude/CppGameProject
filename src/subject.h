#pragma once

#include <list>
#include "observer.h"
#include <algorithm>

using EventHandler = std::function<void()>;

class Subject
{
public:
  void Attach(Observer* const & o);
  void Detach(Observer* const & o);
  void Notify(EventHandler const & event, Box2D box);
protected:
  std::list<Observer*> m_observers;
};
