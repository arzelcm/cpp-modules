#pragma once
#include <cstddef>
template <typename T>
class Array
{
private:
	std::size_t _size;
	T *_elems;

public:
	Array();
	Array(const unsigned int);
	Array(const Array &);
	Array &operator=(const Array &);
	T &operator[](std::size_t) const;
	std::size_t size() const;
	~Array();
};

#include "Array.tpp"