#include "PmergeMe.hpp"
#include "Defines.hpp"

#include <cstdlib>

void PmergeMe::vectorSort()
{
   splitVectorIntoPairs();
   print_vector_pairs(_pairs);
   sortInnerPairMembers(_pairs);
   print_vector_pairs(_pairs);
   recursiveSortPairs(_pairs, _pairs.size());
   print_vector_pairs(_pairs);
}

int PmergeMe::getJacobisthal(int index)
{
   if (index == 0)
      return 0;
   if (index == 1)
      return 1;
   return getJacobisthal(index - 1) + 2 * getJacobisthal(index - 2);
}

void PmergeMe::getArgv(char **argv)
{
   for (int i = 1; argv[i]; i++)
   {
      _unsortedVect.push_back(std::atoi(argv[i]));
      _unsortedList.push_back(std::atoi(argv[i]));
   }
}

void PmergeMe::splitVectorIntoPairs()
{
   _isOdd = _unsortedVect.size() % 2; 
   if (_isOdd)
   {
      _removedElement = _unsortedVect.back();
      _unsortedVect.pop_back();
   }
   std::vector<int>::iterator it = _unsortedVect.begin();
   bool isSecond = false;
    for (; it != _unsortedVect.end(); it++)
    {
        if (isSecond)
        {
            _pairs.push_back(std::make_pair(*(it - 1), *it));
            isSecond = false;
        }
        else
            isSecond = true;
    }
}

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &other) {(void)other;}

PmergeMe &PmergeMe::operator=(const PmergeMe &other) { (void)other; return *this;}

PmergeMe::~PmergeMe() {}

bool PmergeMe::haveNegativeNumbers(char **argv)
{
	for (int i = 1; argv[i]; i++)
	{
		if (std::atoi(argv[i]) < 0)
			return true;
	}
	return false;
}

bool PmergeMe::isSorted(char **argv)
{
	for (int i = 1; argv[i + 1]; i++)
	{
		if (std::atoi(argv[i]) > std::atoi(argv[i + 1]))
			return false;
	}
	return true;
}

void PmergeMe::swapPairMembers(std::pair<int, int> &pair)
{
	int tmp = pair.first;
	pair.first = pair.second;
	pair.second = tmp;
}

void PmergeMe::sortInnerPairMembers(std::vector<std::pair<int, int> > &vect)
{
	std::vector<std::pair<int, int> >::iterator it = vect.begin();

	for (; it != vect.end(); it++)
	{
		if (it->first > it->second)
			swapPairMembers(*it);
	}
}

void PmergeMe::recursiveSortPairs(std::vector<std::pair<int, int> > &vect, int n)
{
	if (n <= 1)
		return;
	recursiveSortPairs(vect, n - 1);
	std::pair<int, int> last = vect[n - 1];
	int j = n - 2;
	while (j >= 0 && vect[j].second > last.second)
	{
		vect[j + 1] = vect[j];
		j--;
	}
	vect[j + 1] = last;
}

int PmergeMe::binaryInsertion (std::vector<int> &vect, int element)
{
	int left, right, mid;
	left = 0;
	right = vect.size();

	while (left < right)
	{
		mid = (left + right) / 2;
		if (element < vect[mid])
			right = mid;
		else
			left = mid + 1;
	}
	vect.insert(vect.begin() + left, element);
	return left;
}