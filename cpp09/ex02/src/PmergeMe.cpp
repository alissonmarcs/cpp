#include "PmergeMe.hpp"
#include "Defines.hpp"

#include <deque>
#include <vector>
#include <iomanip>
#include <algorithm>

PmergeMe::PmergeMe () {}

PmergeMe::PmergeMe (const PmergeMe &other) { (void)other; }

PmergeMe &
PmergeMe::operator= (const PmergeMe &other)
{
  (void)other;
  return *this;
}

PmergeMe::~PmergeMe () {}

PmergeMe::PmergeMe (int argc, char **argv)
{
  if (argc < 2)
    throw std::invalid_argument (
        "Usage: ./PmergeMe [number1] [number2] ... [numberN]");
  else if (haveNegativeNumbers (argv))
    throw std::invalid_argument ("Negative numbers are not allowed");

  std::vector<int> vect;
  std::deque<int> deq;

  for (int i = 1; argv[i]; i++)
    {
      vect.push_back (std::atoi (argv[i]));
      deq.push_back (std::atoi (argv[i]));
    }

  std::vector<int> vectCopy (vect);
  std::deque<int> deqCopy (deq);

  std::cout << YELLOW "Vector before: " RESET;
  printContainer (vect);
  clock_t start = clock ();
  mergeSort<std::vector<int> > (vect, 0, vect.size () - 1);
  clock_t end = clock ();
  std::cout << GREEN "Vector after: " RESET;
  printContainer (vect);
  print ("Time for vector: " << std::fixed << std::setprecision (6)
                             << (double)(end - start) / CLOCKS_PER_SEC << "s");
  std::sort(vectCopy.begin(), vectCopy.end());
  print ("Is vector sorted? " << (vect == vectCopy ? "Yes" : "No"));

  std::cout << YELLOW "Deque before: " RESET;
  printContainer (deq);
  start = clock ();
  mergeSort<std::deque<int> > (deq, 0, vect.size () - 1);
  end = clock ();
  std::cout << GREEN "Deque after: " RESET;
  printContainer (deq);
  print ("Time for deque: " << std::fixed << std::setprecision (6)
                            << (double)(end - start) / CLOCKS_PER_SEC << "s");
  std::sort(deqCopy.begin(), deqCopy.end());
  print ("Is deque sorted? " << (deq == deqCopy ? "Yes" : "No"));
}

template <typename T>
void
PmergeMe::mergeSort (T &container, size_t left, size_t right)
{
  if (left < right)
    {
      size_t mid = left + (right - left) / 2;
      mergeSort (container, left, mid);
      mergeSort (container, mid + 1, right);
      merge (container, left, mid, right);
    }
}

template <typename T>
void
PmergeMe::merge (T &container, size_t left, size_t mid, size_t right)
{
  T leftContainer (container.begin () + left, container.begin () + mid + 1);
  T rightContainer (container.begin () + mid + 1, container.begin () + right + 1);

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

bool
PmergeMe::haveNegativeNumbers (char **argv)
{
  for (int i = 1; argv[i]; i++)
    {
      if (std::atoi (argv[i]) < 0)
        return true;
    }
  return false;
}

template <typename T>
void
printContainer (T &container)
{
  for (typename T::iterator it = container.begin (); it != container.end ();
       ++it)
    std::cout << "[" << *it << "]";
  std::cout << std::endl;
}