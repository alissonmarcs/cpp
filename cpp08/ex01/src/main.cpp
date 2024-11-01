#include <iostream>
#include <vector>

template <typename T>
void print_memory_information (std::vector<T> &vec) {
    std::cout << "\n\t\tMemory memory information\n" << std::endl;
    std::cout << "Size of the vector: " << vec.size() << std::endl;
    std::cout << "Capacity of the vector: " << vec.capacity() << std::endl;
}

template <typename T>
void print_vector (std::vector<T> &vec) {
    std::cout << "\n\t\tVector data\n" << std::endl;
    typename std::vector<T>::iterator it = vec.begin(); 
    for (; it != vec.end(); it++) {
        std::cout << *it << std::endl;
    }
}

int main() {
    std::vector<int> myVector(20);
    // std::vector<int>::iterator it = myVector.begin();

    print_vector(myVector);
    print_memory_information(myVector);
    myVector.push_back(42);
    print_vector(myVector);
    // std::advance(it, 5);
    // myVector.insert(it, 3, 42);
    // print_vector(myVector);

}