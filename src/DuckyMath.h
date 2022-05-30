#pragma once
#include <SFML/Main.hpp>

template <typename T>
const T VecLength(sf::Vector2<T> vec)
{
	return std::sqrt(vec.x * vec.x + vec.y * vec.y);
}

