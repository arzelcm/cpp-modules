#include <exception>
#include "Array.hpp"

template <typename T>
Array<T>::Array() : _size(0), _elems(NULL)
{
}

template <typename T>
Array<T>::Array(const unsigned int n) : _size(n), _elems(new T[n]())
{
}

template <typename T>
Array<T>::Array(const Array &arr) : _size(arr._size), _elems(new T[arr._size]())
{
	for (std::size_t i = 0; i < arr._size; i++)
	{
		this->_elems[i] = arr._elems[i];
	}
}

template <typename T>
Array<T> &Array<T>::operator=(const Array<T> &cpy)
{
	if (this != &cpy)
	{
		delete[] this->_elems;
		this->_elems = NULL;
		this->_size = cpy._size;
		if (this->_size > 0)
		{
			this->_elems = new T[this->_size]();
			for (std::size_t i = 0; i < this->_size; i++)
			{
				this->_elems[i] = cpy._elems[i];
			}
		}
	}
	return *this;
}

template <typename T>
T &Array<T>::operator[](std::size_t i) const
{
	if (i < this->_size)
		return this->_elems[i];
	else
		throw std::out_of_range("Array index is out of bounds");
}

template <typename T>
std::size_t Array<T>::size() const
{
	return this->_size;
}

template <typename T>
Array<T>::~Array()
{
	delete[] this->_elems;
}