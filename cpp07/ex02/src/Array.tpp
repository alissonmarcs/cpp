#pragma once

#include "Array.hpp"
#include "defines.hpp"

template <typename T> Array<T>::Array () : _array (NULL), _size (0){};

template <typename T> Array<T>::Array (size_t n) : _array (NULL), _size (n)
{
  if (n <= 0 || n > MAX_SIZE)
    throw Array<T>::InvalidArraySize ();
  _array = new T[n];
  for (size_t i = 0; i < n; i++)
    _array[i] = T ();
};

template <typename T>
Array<T>::Array (Array<T> const &other) : _array (NULL), _size (other.size ())
{
  if (other.size () == 0)
    throw Array<T>::EmptyArray ();
  _array = new T[other.size ()];
  for (size_t i = 0; i < other.size (); i++)
    _array[i] = other._array[i];
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
const T &
Array<T>::operator[] (size_t i) const
{
  if (_array == NULL)
    throw Array<T>::EmptyArray ();
  if (i >= _size)
    throw Array<T>::OutOfLimitsException ();
  return _array[i];
};

template <typename T>
Array<T> &
Array<T>::operator= (const Array<T> &rhs)
{
  if (rhs.size () == 0)
    throw Array<T>::EmptyArray ();
  if (this != &rhs)
    {
      if (this->size () != rhs.size ())
        {
          if (_array)
            delete[] _array;
          _array = new T[rhs.size ()];
          _size = rhs.size ();
        }
      for (size_t i = 0; i < rhs.size (); i++)
        _array[i] = rhs[i];
    }
  return *this;
};

template <typename T>
const char *
Array<T>::InvalidArraySize::what () const throw ()
{
  return RED "Invalid array size in constructor" RESET;
};

template <typename T>
const char *
Array<T>::OutOfLimitsException::what () const throw ()
{
  return RED "Invalid index" RESET;
};

template <typename T>
const char *
Array<T>::EmptyArray::what () const throw ()
{
  return RED "Empty array" RESET;
};

template <typename T> Array<T>::~Array ()
{
  if (_array)
    delete[] _array;
}
