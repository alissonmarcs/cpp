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

void print_array(int *arr, int n)
{
	for (int i = 0; i < n; i++)
		std::cout << "[" << arr[i] << "]";
	std::cout << std::endl;
}

void print_vector_pairs(std::vector<std::pair<int, int> > &vect)
{
	std::cout << YELLOW "Vector pairs: " RESET ;
	for (std::vector<std::pair<int, int> >::iterator it = vect.begin(); it != vect.end(); it++)
		std::cout << "[" << it->first << "--" << it->second << "]";
	std::cout << std::endl;
}

void swapPairMembers(std::pair<int, int> &pair)
{
	int tmp = pair.first;
	pair.first = pair.second;
	pair.second = tmp;
}

void sortInnerPairMembers(std::vector<std::pair<int, int> > &vect)
{
	std::vector<std::pair<int, int> >::iterator it = vect.begin();

	for (; it != vect.end(); it++)
	{
		if (it->first > it->second)
			swapPairMembers(*it);
	}
}

void recursiveSortPairs(std::vector<std::pair<int, int> > &vect, int n)
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

int binary_search(int *array, int size, int target)
{
	int left, right, mid;
	left = 0;
	right = size - 1;

	while (left <= right)
	{
		mid = (right + left) / 2;
		if (array[mid] == target)
			return mid;
		if (array[mid] < target)
			left = mid + 1;
		else
			right = mid - 1;
	}
	return -1;
}

int main(int argc, char const *argv[])
{
	std::srand(std::time(NULL));
	int array[10];
	for (int i = 0; i < 10; i++)
		array[i] = std::rand() % 100;
	print_array(array, 10);
	insertionSortRecursive(array, 10);
	print_array(array, 10);
	std::cout << "element 50 is at index: " << binary_search(array, 10, 50) << std::endl;
    return 0;
}
