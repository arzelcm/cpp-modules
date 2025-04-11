#pragma once
#include "iostream"

class Brain
{
private:
	std::string _ideas[100];

public:
	Brain();
	Brain(const Brain &);
	const std::string *getIdeas() const;
	Brain &operator=(const Brain &);
	~Brain();
};