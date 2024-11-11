#include "PmergeMe.hpp"
#include "Defines.hpp"

#include <iomanip>
#include <cstdlib>

/* Vector */
void
PmergeMe::mergeInsertionSort (std::vector<int> & container, size_t left, size_t right)
{
  if (left < right)
    {
      size_t mid = left + (right - left) / 2;
      mergeInsertionSort (container, left, mid);
      mergeInsertionSort (container, mid + 1, right);
      merge (container, left, mid, right);
    }
}

void
PmergeMe::merge (std::vector<int> & container, size_t left, size_t mid, size_t right)
{
  std::vector<int> leftContainer (container.begin () + left, container.begin () + mid + 1);
  std::vector<int> rightContainer (container.begin () + mid + 1, container.begin () + right + 1);

  size_t i = 0, j = 0, k = left;
  while (i < leftContainer.size () && j < rightContainer.size ())
    {
      if (leftContainer[i] <= rightContainer[j])
        {
          container[k] = leftContainer[i];
          i++;
        }
      else
        {
          container[k] = rightContainer[j];
          j++;
        }
      k++;
    }
  while (i < leftContainer.size ())
    {
      container[k] = leftContainer[i];
      i++;
      k++;
    }
  while (j < rightContainer.size ())
    {
      container[k] = rightContainer[j];
      j++;
      k++;
    }
}

/* Deque */
void
PmergeMe::mergeInsertionSort (std::deque<int> & container, size_t left, size_t right)
{
  if (left < right)
    {
      size_t mid = left + (right - left) / 2;
      mergeInsertionSort (container, left, mid);
      mergeInsertionSort (container, mid + 1, right);
      merge (container, left, mid, right);
    }
}

void
PmergeMe::merge (std::deque<int> & container, size_t left, size_t mid, size_t right)
{
  std::deque<int> leftContainer (container.begin () + left, container.begin () + mid + 1);
  std::deque<int> rightContainer (container.begin () + mid + 1, container.begin () + right + 1);

  size_t i = 0, j = 0, k = left;
  while (i < leftContainer.size () && j < rightContainer.size ())
    {
      if (leftContainer[i] <= rightContainer[j])
        {
          container[k] = leftContainer[i];
          i++;
        }
      else
        {
          container[k] = rightContainer[j];
          j++;
        }
      k++;
    }
  while (i < leftContainer.size ())
    {
      container[k] = leftContainer[i];
      i++;
      k++;
    }
  while (j < rightContainer.size ())
    {
      container[k] = rightContainer[j];
      j++;
      k++;
    }
}

/* Utils */
bool
haveNegativeNumbers (char **argv)
{
  for (int i = 1; argv[i]; i++)
    {
      if (std::atoi (argv[i]) < 0)
        return true;
    }
  return false;
}

PmergeMe::PmergeMe () {}

PmergeMe::PmergeMe (const PmergeMe &other) { (void)other; }

PmergeMe &
PmergeMe::operator= (const PmergeMe &other)
{
  (void)other;
  return *this;
}

PmergeMe::~PmergeMe () {}