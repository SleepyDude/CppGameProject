#pragma once

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
