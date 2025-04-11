#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain default constructor called." << std::endl;
}

Brain::Brain(const Brain &brain)
{
	std::cout << "Brain copy constructor called." << std::endl;
	*this = brain;
}

const std::string *Brain::getIdeas() const
{
	return this->_ideas;
}

Brain &Brain::operator=(const Brain &brain)
{
	if (this == &brain)
		return *this;
	*this->_ideas = *brain._ideas;
	return *this;
}

Brain::~Brain()
{
	std::cout << "Brain destructor called." << std::endl;
}