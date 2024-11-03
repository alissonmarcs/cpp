#pragma once

#include <algorithm>
#include <iterator>
#include <stdexcept>

#include "Defines.hpp"

template <typename T>
typename T::iterator
easyfind (T &container, int target)
{
  typename T::iterator it;

  it = std::find (container.begin (), container.end (), target);
  if (it == container.end ())
    throw std::out_of_range (RED "Element not found" RESET);
  return it;
}