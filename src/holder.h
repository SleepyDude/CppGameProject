#pragma once
#include <functional>
#include <ostream>

class Holder
{
public:
  Holder() = default;

  unsigned int const & ammo() const;
  void SetAmmo(unsigned int ammo);
  Holder & operator -- ();
  Holder operator -- (int);
private:
  unsigned int m_ammo = 20;
};

std::ostream & operator << (std::ostream & os, Holder const & obj);
