#pragma once

#include <cstdlib>

class PmergeMe
{
public:
  PmergeMe ();
  PmergeMe (const PmergeMe &other);
  PmergeMe &operator= (const PmergeMe &other);
  ~PmergeMe ();

  PmergeMe (int argc, char **argv);
  template <typename T>
  void merge (T &container, size_t left, size_t mid, size_t right);
  template <typename T>
  void mergeSort (T &container, size_t left, size_t right);
  bool haveNegativeNumbers (char **argv);
};

template <typename T> void printContainer (T &container);