#include "holder.h"

unsigned int const & Holder::ammo() const { return m_ammo; }

void Holder::SetAmmo(unsigned int ammo)
{
  if ( ammo < 0 || ammo > 100)
  {
    throw std::invalid_argument("ammo must be in range 0..100");
  }
  m_ammo = ammo;
}

Holder & Holder::operator -- ()
{
  if (m_ammo != 0)
  {
    m_ammo--;
  }
  return *this;
}

Holder Holder::operator -- (int)
{
  Holder temp = *this;
  if (m_ammo != 0)
  {
    --*this;
  }
  return temp;
}
