#ifndef B__B_HPP_
#define B__B_HPP_

#include <iostream>

#include <C/C.hpp>

namespace B {
void
print()
{
  std::cout << C::c_message << "\n";
}
}  // namespace B

#endif  // B__B_HPP_
