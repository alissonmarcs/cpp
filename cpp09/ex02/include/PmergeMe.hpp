#pragma once

#include <vector>
#include <deque>
#include <iostream>

class PmergeMe
{
public:
  PmergeMe ();
  PmergeMe (const PmergeMe &other);
  PmergeMe &operator= (const PmergeMe &other);
  ~PmergeMe ();


  /* Vector */
  void merge (std::vector<int> & container, size_t left, size_t mid, size_t right);
  void mergeInsertionSort (std::vector<int> & container, size_t left, size_t right);

  /* Deque */
  void merge (std::deque<int> & container, size_t left, size_t mid, size_t right);
  void mergeInsertionSort (std::deque<int> & container, size_t left, size_t right);
};

bool haveNegativeNumbers (char **argv);

template <typename T>
void
printContainer (T &container)
{
  for (typename T::iterator it = container.begin (); it != container.end ();
       ++it)
    std::cout << "[" << *it << "]";
  std::cout << std::endl;
};