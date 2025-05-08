#pragma once
#include "easyfind.hpp"
#include <exception>
#include <iostream>
#include <sstream>
#include <algorithm>

static std::string getErrMsg(int v)
{
	std::ostringstream res;
	res << v << " not found";
	return res.str();
}

template <typename T>
void easyfind(T &cont, int v)
{
	typename T::iterator elem = std::find(cont.begin(), cont.end(), v);
	if (elem == cont.end())
		throw std::runtime_error(getErrMsg(v));
	else
		std::cout << "Found " << v << " at index " << std::distance(cont.begin(), elem) << std::endl;
}
