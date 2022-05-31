#pragma once
#include <SFML/Main.hpp>

template <typename T>
const float VecLength(sf::Vector2<T> vec)
{
	return std::sqrt(vec.x * vec.x + vec.y * vec.y);
}

template <typename T>
sf::Vector2<T> operator/(sf::Vector2<T> lhs, float rhs)
{
	if (rhs == 0.f)
		return lhs;
	return sf::Vector2<T>(lhs.x / rhs, lhs.y / rhs);
}
