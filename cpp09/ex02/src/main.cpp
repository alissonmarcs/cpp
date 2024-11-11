#include "Defines.hpp"
#include "PmergeMe.hpp"

#include <iomanip>
#include <cstdlib>
#include <algorithm>

int
main (int argc, char **argv)
{
  if (argc < 2)
    {
      print (RED_BOLD "Usage: " RESET GREEN_BOLD "./PmergeMe" RESET YELLOW_BOLD " [n1] [n2] [n3] ... [n]" RESET);
      return 1;
    }
  else if (haveNegativeNumbers (argv))
    {
      print (RED_BOLD "Error: " RESET YELLOW_BOLD "Only positive numbers are allowed" RESET);
      return 1;
    }
  
  std::deque<int> deq;
  std::vector<int> vect;

  for (int i = 1; argv[i]; i++)
    {
      deq.push_back (std::atoi (argv[i]));
      vect.push_back (std::atoi (argv[i]));
    }
  
  PmergeMe pmergeMe;
  std::vector<int> vectCopy (vect);
  std::deque<int> deqCopy (deq);
  
  std::cout << "Before: ";
  printContainer (deq);
  
  clock_t start = clock ();
  pmergeMe.mergeInsertionSort (deq, 0, deq.size () - 1);
  clock_t end = clock ();
  
  std::cout << "After: ";
  printContainer (deq);
  print ("Time for deque: " << std::fixed << std::setprecision (6) << (double) (end - start) / CLOCKS_PER_SEC << " seconds");

  start = clock ();
  pmergeMe.mergeInsertionSort (vect, 0, vect.size () - 1);
  end = clock ();
  print ("Time for vector: " << std::fixed << std::setprecision (6) << (double) (end - start) / CLOCKS_PER_SEC << " seconds");

  std::sort(vectCopy.begin(), vectCopy.end());
  std::sort(deqCopy.begin(), deqCopy.end());

  std::cout << "System sort are equal to insertion merge sort for deques: " << ((deqCopy == deq) ? "Yes" : "No") << std::endl;
  std::cout << "System sort are equal to insertion merge sort for vectors: " << ((vectCopy == vect) ? "Yes" : "No") << std::endl;
}