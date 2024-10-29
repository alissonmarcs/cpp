#include <Array.hpp>
#include <cstdlib>
#include <iostream>
#include <string.h>

#include "defines.hpp"

int
main (void)
{
  print (YELLOW_BOLD TITTLE "CPP Molule 07 - ex02" RESET);

  print (YELLOW SUB_TITTLE "Constructors\n" RESET);
  {
    Array<int> array1 (500);
    Array<int> array2;

    print (PURPLE "Array1 size: " RESET << array1.size ());
    print (PURPLE "Array2 size: " RESET << array2.size ());

    try
      {
        Array<int> array3 (-42);
      }
    catch (std::exception &e)
      {
        print (e.what ());
      }
  }

  print (YELLOW SUB_TITTLE "Subscript operator\n" RESET);
  {
    const char *message = "Batman";
    Array<std::string> array (strlen (message));

    for (size_t i = 0; message[i]; i++)
      array[i] = message[i];

    for (size_t i = 0; i < array.size (); i++)
      print (PURPLE "array[" << i << "] = " RESET << array[i]);

    try
      {
        print (PURPLE "array[42] = " RESET << array[42]);
      }
    catch (std::exception &e)
      {
        print (e.what ());
      }
  }

  print (YELLOW SUB_TITTLE "Copy constructor\n" RESET);
  {
    Array<std::string> array (3);
    const char *messages[] = { "Hello", "World", "!" };

    for (size_t i = 0; i < array.size (); i++)
      array[i] = messages[i];

    {
      Array<std::string> copy (array);
      for (size_t i = 0; i < array.size (); i++)
        print (PURPLE "array[" << i << "] = " RESET << array[i]);

      std::cout << std::endl;
      for (size_t i = 0; i < copy.size (); i++)
        print (PURPLE "copy[" << i << "] = " RESET << copy[i]);

      std::cout << std::endl;
      print ("copy[2] = \"Batman\"" << ";" << RESET);
      std::cout << std::endl;

      copy[2] = "Batman";
      print (PURPLE "copy[2] = " RESET << copy[2]);
      print (PURPLE "array[2] = " RESET << array[2]);
    }
  }

  print (YELLOW SUB_TITTLE "Assigment operator\n" RESET);
  {
    Array<std::string> array (3);
    const char *messages[] = { "Hello", "World", "!" };

    for (size_t i = 0; i < array.size (); i++)
      array[i] = messages[i];

    {
      Array<std::string> copy;
      copy = array;
      for (size_t i = 0; i < array.size (); i++)
        print (PURPLE "array[" << i << "] = " RESET << array[i]);

      std::cout << std::endl;

      for (size_t i = 0; i < copy.size (); i++)
        print (PURPLE "copy[" << i << "] = " RESET << copy[i]);

      std::cout << std::endl;
      print ("copy[2] = \"Batman\"" << ";" << RESET);
      std::cout << std::endl;

      copy[2] = "Batman";
      print (PURPLE "copy[2] = " RESET << copy[2]);
      print (PURPLE "array[2] = " RESET << array[2]);
    }
  }
}