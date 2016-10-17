#pragma once

class Scalable
{
public:
  virtual ~Scalable() = default;
  virtual void Scale(float factor) = 0;
};
