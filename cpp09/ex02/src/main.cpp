#include "Defines.hpp"
#include "PmergeMe.hpp"

#include <cstdlib>
#include <ctime>
#include <deque>
#include <vector>

#include <vector>

int
main (int argc, char **argv)
{
  try
    {
      PmergeMe pmergeMe (argc, argv);
    }
  catch (const std::exception &e)
    {
      std::cerr << e.what () << '\n';
    }
}