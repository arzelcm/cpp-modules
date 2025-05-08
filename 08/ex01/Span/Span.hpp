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
	Span(Span &);
	void addNumber(int); // Throws
	int shortestSpan();	 // Throws
	int longestSpan();	 // Throws
	Span &operator=(Span &);
	~Span();
};