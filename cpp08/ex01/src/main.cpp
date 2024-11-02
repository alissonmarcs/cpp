#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <numeric>
#include <vector>

#include "Defines.hpp"
#include "Span.hpp"

int
main ()
{
  print (TITTLE YELLOW_BOLD "CPP Module 08 - ex01" RESET);
  {
    print (SUB_TITTLE GREEN
           "Exception when try to fill out of bounds - addNumber()\n" RESET);
    Span sp = Span (5);
    try
      {
        sp.addNumber (1);
        sp.addNumber (2);
        sp.addNumber (3);
        sp.addNumber (4);
        sp.addNumber (5);
        sp.addNumber (6);
      }
    catch (std::exception &e)
      {
        print (e.what ());
      }
  }
  {
    print (SUB_TITTLE GREEN
           "Exception when try to fill out of bounds - populate()\n" RESET);
    Span sp = Span (5);
    std::vector<int> v (6, 42);
    try
      {
        sp.populate (v.begin (), v.end ());
      }
    catch (std::exception &e)
      {
        print (e.what ());
      }
  }
  {
    print (SUB_TITTLE GREEN "populate() with a valid range\n" RESET);
    Span sp = Span (10);
    std::vector<int> v (10, -42);

    sp.populate (v.begin (), v.end ());
    sp.operator<< (std::cout);
  }
  {
    print (SUB_TITTLE GREEN "Exception when try to calculate shortestSpan() "
                            "with less than 2 numbers\n" RESET);
    Span sp = Span (5);
    try
      {
        sp.shortestSpan ();
      }
    catch (std::exception &e)
      {
        print (e.what ());
      }
  }
  {
    print (SUB_TITTLE GREEN "Exception when try to calculate longestSpan() "
                            "with less than 2 numbers\n" RESET);
    Span sp = Span (5);
    try
      {
        sp.longestSpan ();
      }
    catch (std::exception &e)
      {
        print (e.what ());
      }
  }
  std::srand (std::time (0));
  {
    print (
        SUB_TITTLE GREEN
        "shortestSpan() and longestSpan() with a few random numbers\n" RESET);
    Span sp (15);

    for (int i = 0; i < 15; i++)
      sp.addNumber (std::rand () % 200);
    print (YELLOW "shortestSpan(): " RESET << sp.shortestSpan ());
    print (YELLOW "longestSpan(): " RESET << sp.longestSpan ());
    sp.operator<< (std::cout);
  }
  {
    print (
        SUB_TITTLE GREEN
        "shortestSpan() and longestSpan() with 20000 random numbers\n" RESET);
    Span sp (20000);

    for (int i = 0; i < 20000; i++)
      sp.addNumber (std::rand ());
    print (YELLOW "shortestSpan(): " RESET << sp.shortestSpan ());
    print (YELLOW "longestSpan(): " RESET << sp.longestSpan ());
  }
}