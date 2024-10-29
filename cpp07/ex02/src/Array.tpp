#pragma once

#include "Array.hpp"

template <typename T> Array<T>::Array () : _array (NULL), _size (0){};

template <typename T> Array<T>::Array (size_t n) : _array (NULL), _size (n)
{
  if (n <= 0)
    throw Array<T>::InvalidArraySize ();
  _array = new T[n];
  for (size_t i = 0; i < n; i++)
    _array[i] = T ();
};

template <typename T>
size_t
Array<T>::size () const
{
  return _size;
};

template <typename T>
T &
Array<T>::operator[] (size_t i)
{
  if (_array == NULL)
    throw Array<T>::EmptyArray ();
  if (i >= _size)
    throw Array<T>::OutOfLimitsException ();
  return _array[i];
};

template <typename T>
const char *
Array<T>::InvalidArraySize::what () const throw ()
{
  return "Invalid array size in constructor";
};

template <typename T>
const char *
Array<T>::OutOfLimitsException::what () const throw ()
{
  return "Invalid index";
};

template <typename T>
const char *
Array<T>::EmptyArray::what () const throw ()
{
  return "Empty array";
};

template <typename T> Array<T>::~Array ()
{
  if (_array)
    delete[] _array;
}
