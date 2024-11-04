#include "Defines.hpp"
#include "easyfind.hpp"

#include <cstdlib>
#include <ctime>
#include <deque>
#include <list>
#include <vector>

int
main ()
{
  print (YELLOW_BOLD TITTLE "CPP Module 08 - ex00" RESET);
  std::srand (std::time (0));
  {
    print (
        GREEN SUB_TITTLE
        "easyfind() must throw an exception if element is not found\n" RESET);
    std::deque<int> deq;
    for (int i = 0; i < 10; i++)
      deq.push_back (i);
    try
      {
        print (YELLOW "Element found: " RESET << *easyfind (deq, 500));
      }
    catch (std::exception &e)
      {
        print (e.what ());
      }
  }
  {
    print (GREEN SUB_TITTLE "easyfind() working with a list\n" RESET);
    std::list<int> lst;
    for (int i = -10; i < 0; i++)
      lst.push_back (i);
    try
      {
        print (YELLOW "Element found: " RESET << *easyfind (lst, -4));
      }
    catch (std::exception &e)
      {
        print (e.what ());
      }
  }
  {
    print (GREEN SUB_TITTLE "easyfind() working with a deque\n" RESET);
    std::deque<int> deq;
    for (int i = 200; i < 210; i++)
      deq.push_back (i);
    try
      {
        print (YELLOW "Element found: " RESET << *easyfind (deq, 209));
      }
    catch (std::exception &e)
      {
        print (e.what ());
      }
  }
  {
    print (GREEN SUB_TITTLE "easyfind() working with a vector\n" RESET);
    std::vector<int> vec;
    for (int i = 910; i < 1000; i++)
      vec.push_back (i);
    try
      {
        print (YELLOW "Element found: " RESET << *easyfind (vec, 910));
      }
    catch (std::exception &e)
      {
        print (e.what ());
      }
  }
}