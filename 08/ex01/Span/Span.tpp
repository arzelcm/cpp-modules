#include "Span.hpp"
#include <stdexcept>
#include <iterator>

template <typename InputIt>
void Span::addNumber(InputIt begin, InputIt end)
{
	if (std::distance(begin, end) + this->_lastI > this->_size)
		throw std::overflow_error("Range doesn't fit in Span");
	for (InputIt it = begin; it != end; ++it)
	{
		this->addNumber(*it);
	}
}