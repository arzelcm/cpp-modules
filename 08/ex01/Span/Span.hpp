#pragma once

class Span
{
private:
	unsigned int _size;
	unsigned int _lastI;
	int *_elems;

public:
	Span();
	Span(unsigned int);
	Span(const Span &);
	void addNumber(const int); // Throws
	template <typename InputIt>
	void addNumber(InputIt begin, InputIt end); // Throws
	int shortestSpan() const;					// Throws
	int longestSpan() const;					// Throws
	void listNumbers() const;
	Span &operator=(const Span &);
	~Span();
};

#include "Span.tpp"