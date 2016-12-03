#pragma once

class Scalable
{
public:
  virtual ~Scalable() = default;
  virtual void Scale(float factorW,float factorH) = 0;
};
