#pragma once
#include <array>

template <typename T, typename F>
void iter(T *arr, std::size_t len, F callback)
{
	if (arr)
		for (std::size_t i = 0; arr && i < len; i++)
			callback(arr[i]);
}