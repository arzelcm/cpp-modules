#include "Span.hpp"
#include <cstddef>
#include <algorithm>
#include <stdexcept>
#include <iostream>

Span::Span() : _size(0), _lastI(0), _elems(new int[this->_size]())
{
}

Span::Span(unsigned int n) : _size(n), _lastI(0), _elems(new int[this->_size]())
{
}

Span::Span(const Span &cpy) : _elems(NULL)
{
	*this = cpy;
}

void Span::addNumber(const int n)
{
	if (this->_lastI >= this->_size)
		throw std::overflow_error("Span is full");

	this->_elems[this->_lastI] = n;
	this->_lastI++;
}

int Span::shortestSpan() const
{
	if (this->_lastI <= 1)
		throw std::logic_error("Insufficient numbers to calculate shortest span");
	int shortestSpan = std::numeric_limits<int>::max();
	int current_diff = 0;
	std::sort(this->_elems, this->_elems + this->_lastI);
	for (unsigned int i = 0; i < this->_lastI - 1; i++)
	{
		current_diff = this->_elems[i + 1] - this->_elems[i];
		if (current_diff < shortestSpan)
			shortestSpan = current_diff;
	}
	return shortestSpan;
}

int Span::longestSpan() const
{
	if (this->_lastI <= 1)
		throw std::logic_error("Insufficient numbers to calculate longest span");

	const int *max = std::max_element(this->_elems, this->_elems + this->_lastI);
	const int *min = std::min_element(this->_elems, this->_elems + this->_lastI);

	return std::abs(*max - *min);
}

void	Span::listNumbers() const
{
	for (unsigned int i = 0; i < this->_lastI; i++)
		std::cout << this->_elems[i] << " ";
	std::cout << std::endl;
}

Span &Span::operator=(const Span &cpy)
{
	this->_size = cpy._size;
	this->_lastI = cpy._lastI;
	delete[] this->_elems;
	this->_elems = NULL;
	if (this->_size > 0)
	{
		this->_elems = new int[this->_size]();
		for (size_t i = 0; i < this->_size; i++)
		{
			this->_elems[i] = cpy._elems[i];
		}
	}
	return *this;
}

Span::~Span()
{
	delete[] this->_elems;
}
