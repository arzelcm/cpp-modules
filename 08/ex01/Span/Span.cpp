#include "Span.hpp"

Span::Span() : _size(0), _lastI(0), _elems(new Int[this->size]())
{
}

Span::Span(unsigned int n) : _size(n), _lastI(0), _elems(new Int[n]())
{
}

Span::Span(Span &cpy)
{
	*this = cpy;
}

void Span::addNumber(int n)
{
}

int Span::shortestSpan()
{
}

int Span::longestSpan()
{
}

Span &Span::operator=(Span &cpy)
{
	this->_size = cpy._size;
	this->_lastI = cpy._lastI;
	delete[] this->_elems;
	this->_elems = NULL;
	if (this->_size > 0)
	{
		this->_elems = new Int[this->_size]();
		for (size_t i = 0; i < this->_size; i++)
		{
			this->_elems[i] = cpy._elems[i];	
		}
	}
}

Span::~Span()
{
	delete[] this->_elems;
}
