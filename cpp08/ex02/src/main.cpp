#include "Defines.hpp"
#include "MutantStack.hpp"

#include <list>
#include <vector>

int
main (void)
{
  print (TITTLE YELLOW_BOLD "CPP Module 08 - ex02" RESET);
  print (SUB_TITTLE YELLOW
         "Int stack with default underlying deque container" RESET);

  MutantStack<int> mstack;

  mstack.push (5);
  mstack.push (17);
  mstack.push (3);
  mstack.push (5);
  mstack.push (737);
  mstack.push (0);

  MutantStack<int>::iterator it, ite;
  it = mstack.begin ();
  ite = mstack.end ();
  for (; it != ite; ++it)
    print (*it);

  print (SUB_TITTLE YELLOW
         "String stack with vector as underlying container" RESET);
  MutantStack<std::string, std::vector<std::string> > mstack2;

  mstack2.push ("Hello");
  mstack2.push ("World");
  mstack2.push ("!");
  mstack2.push ("I'm");
  mstack2.push ("a");
  mstack2.push ("MutantStack");

  MutantStack<std::string, std::vector<std::string> >::iterator it2, ite2;
  it2 = mstack2.begin ();
  ite2 = mstack2.end ();
  for (; it2 != ite2; ++it2)
    print (*it2);

  MutantStack<float, std::list<float> > mstack3;

  mstack3.push (5.5);
  mstack3.push (17.17);
  mstack3.push (3.3);
  mstack3.push (5.5);
  mstack3.push (737.737);
  mstack3.push (0.0);

  print (SUB_TITTLE YELLOW
         "Float stack with list as underlying container" RESET);
  MutantStack<float, std::list<float> >::iterator it3, ite3;
  it3 = mstack3.begin ();
  ite3 = mstack3.end ();
  for (; it3 != ite3; ++it3)
    print (*it3);

  print (SUB_TITTLE YELLOW "Copy construcor" RESET);
  MutantStack<float, std::list<float> > copy (mstack3);
  MutantStack<float, std::list<float> >::iterator it4, ite4;
  it4 = copy.begin ();
  ite4 = copy.end ();
  for (; it4 != ite4; ++it4)
    print (*it4);

  print (SUB_TITTLE YELLOW "Assignment operator" RESET);
  MutantStack<float, std::list<float> > assign; 
  assign = mstack3;
  MutantStack<float, std::list<float> >::iterator it5, ite5;
  it5 = assign.begin ();
  ite5 = assign.end ();
  for (; it5 != ite5; ++it5)
    print (*it5);
}