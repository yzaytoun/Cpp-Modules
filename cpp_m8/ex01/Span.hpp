/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 13:31:01 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/10/26 15:43:54 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <exception>
#include <limits>

class Span
{
private:
	const std::size_t	_size;
	std::vector<int>	_numbers;
public:
	Span(unsigned int N);
	~Span();

	/* Methods */
	void    addNumber(const int& num);
	void    addMany(const std::vector<int>& many);
	int     shortestSpan(void) const;
	int		longestSpan(void) const;

	/* Exceptions */
	class LimitReached : public std::exception
	{
		public:
			const char* what() const throw()
			{
				return ("Reached Span limit");
			};
	};

	class SpanNotFound : public std::exception
	{
		public:
			const char* what() const throw()
			{
				return ("Span not found");
			};
	};
	
	class InvalidSpanSize : public std::exception
	{
		public:
			const char* what() const throw()
			{
				return ("Invalid Span Size");
			};
	};
};

