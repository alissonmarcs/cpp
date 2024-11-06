#pragma once

#include <vector>
#include <list>

class PmergeMe
{
	private:
		std::vector<int> _unsortedVect;
		std::vector<int> _sortedVect;
		std::vector<std::pair<int, int> > _pairs;
		bool _isOdd;
		int _removedElement;
		std::list<int> _unsortedList;
		std::list<int> _sortedList;

	public:
		PmergeMe();
		PmergeMe(const PmergeMe &other);
		PmergeMe &operator=(const PmergeMe &other);
		~PmergeMe();

		static bool isSorted(char **argv);
		static bool haveNegativeNumbers(char **argv);
		void getArgv(char **argv);

		void vectorSort();
		void swapPairMembers(std::pair<int, int> &pair);
		void sortInnerPairMembers(std::vector<std::pair<int, int> > &vect);
		void recursiveSortPairs(std::vector<std::pair<int, int> > &vect, int n);
		int binaryInsertion (std::vector<int> &vect, int element);
		void splitVectorIntoPairs();
		int getJacobisthal(int index);
		std::vector<int> generateJacobSequence(int pendingSize);
};

void print_vector(std::vector<int> &vect);
void print_vector_pairs(std::vector<std::pair<int, int> > &vect);