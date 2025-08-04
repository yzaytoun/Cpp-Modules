/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 13:29:49 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/10/26 15:42:50 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(unsigned int N) : _size(N)
{
	if (N < 1)
		throw InvalidSpanSize();
}

Span::~Span()
{
	_numbers.clear();
}

Span::Span(const Span& s) : _size(s.getSize()), _numbers(s.getSpanValues()) {}

Span&	Span::operator=(const Span& s)
{
	if (this != &s)
	{
		this->_size = s.getSize();
		this->_numbers = s.getSpanValues();
	}
	return (*this);
}

std::size_t	Span::getSize(void) const
{
	return (_size);
}

std::vector<int>	Span::getSpanValues(void) const
{
	return (_numbers);
}

void	Span::addNumber(const int& num)
{
	if ((_numbers.size() + 1) > _size)
		throw LimitReached();
	_numbers.push_back(num);
}

void    Span::addMany(const std::vector<int>& many)
{
	for (size_t i = 0; i < many.size(); i++)
		addNumber(many[i]);
}

int 	Span::longestSpan(void) const
{
	int	distance = 0;
	int	max_distance = 0;
	std::vector<int>::const_iterator	itr_1;
	std::vector<int>::const_iterator	itr_2;

	if (_numbers.size() < 2)
		throw SpanNotFound();
	for (itr_1 = _numbers.begin(); itr_1 != _numbers.end(); itr_1++)
	{
		for (itr_2 = itr_1; itr_2 != _numbers.end(); itr_2++)
		{
			distance = std::abs(*itr_1 - *itr_2);
			if (distance && distance > max_distance)
				max_distance = distance;
		}
	}
	return (max_distance);
}

int 	Span::shortestSpan(void) const
{
	int	distance = 0;
	int	min_distance = _size;
	std::vector<int>::const_iterator	itr_1;
	std::vector<int>::const_iterator	itr_2;

	if (_numbers.size() < 2)
		throw SpanNotFound();
	for (itr_1 = _numbers.begin(); itr_1 != _numbers.end(); itr_1++)
	{
		for (itr_2 = itr_1; itr_2 != _numbers.end(); itr_2++)
		{
			distance = std::abs(*itr_1 - *itr_2);
			if (distance && distance < min_distance)
				min_distance = distance;
		}
	}
	return (min_distance);
}
