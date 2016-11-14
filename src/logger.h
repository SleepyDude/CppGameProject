#pragma once

#include <iostream>
#include <sstream>

class Logger
{
public:
  static Logger & Instance()
  {
    static Logger inst;
    return inst;
  }

  template<typename T, template<typename, typename...> class C, typename... Args>
  Logger & operator << (C<T, Args...> const & objs)
  {
    m_os << "**Container**\n";
    for (auto const & obj : objs)
      m_os << " " << obj;
    return *this;
  }

  template <typename T>
  Logger & operator << (T const & obj)
  {
    m_os << obj;
    return *this;
  }

private:
  std::ostream & m_os = std::cout;
  Logger() = default;
  Logger(std::ostream & os);
  virtual ~Logger() = default;
  Logger(Logger const &) = delete;
  Logger & operator = (Logger const &) = delete;
  Logger(Logger &&) = delete;
  Logger & operator = (Logger &&) = delete;
};
