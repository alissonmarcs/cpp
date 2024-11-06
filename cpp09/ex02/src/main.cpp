#include "Defines.hpp"
#include "PmergeMe.hpp"

#include <vector>
#include <ctime>
#include <cstdlib>

void insertionSortRecursive(int *arr, int n)
{
	if (n <= 1)
		return;
	insertionSortRecursive(arr, n - 1);
	int last = arr[n - 1];
	int j = n - 2;
	while (j >= 0 && arr[j] > last)
	{
		arr[j + 1] = arr[j];
		j--;
	}
	arr[j + 1] = last;
}

int binary_search(int *array, int size, int target)
{
	int left, right, mid;
	left = 0;
	right = size - 1;

	while (left <= right)
	{
		mid = (left + right ) / 2;
		if (array[mid] == target)
			return mid;
		if (target < array[mid])
			right = mid - 1;
		else
			left = mid + 1;
	}
	return -1;
}

void print_array(int *arr, int n)
{
	for (int i = 0; i < n; i++)
		std::cout << "[" << arr[i] << "]";
	std::cout << std::endl;
}

void print_vector_pairs(std::vector<std::pair<int, int> > &vect)
{
	std::cout << YELLOW "Vector pairs data: " RESET ;
	for (std::vector<std::pair<int, int> >::iterator it = vect.begin(); it != vect.end(); it++)
		std::cout << "[" << it->first << "--" << it->second << "]";
	std::cout << std::endl;
}

void print_vector(std::vector<int> &vect)
{
	std::cout << YELLOW "Vector data: " RESET ;
	for (std::vector< int>::iterator it = vect.begin(); it != vect.end(); it++)
		std::cout << "[" << *it << "]";
	std::cout << std::endl;
}

int main(int argc, char **argv)
{
	if (argc == 1)
	{
		print (RED "Usage: ./pmergeMe [number1] [number2] [number3] ... [numberN]" RESET);
	}
	else if (PmergeMe::haveNegativeNumbers(argv))
		print (RED "Please provide only positive numbers" RESET);
	else if (PmergeMe::isSorted(argv))
	{
		print (RED "Please provide an unsorted array" RESET);
	}
	PmergeMe pmergeMe;
	// pmergeMe.getArgv(argv);
	// pmergeMe.vectorSort();

	print (YELLOW "jacob sequence for 83: " RESET);
	std::vector<int> jacob = pmergeMe.generateJacobSequence(83);
	print_vector(jacob);
}
