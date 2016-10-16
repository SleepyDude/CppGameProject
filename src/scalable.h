#pragma once

class Scalable
{
public:
  virtual ~Scalable();
  virtual void Scale(float factor) = 0;
};
