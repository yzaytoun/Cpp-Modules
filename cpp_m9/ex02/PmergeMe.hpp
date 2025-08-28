/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp  			                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 13:31:01 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/10/26 15:43:54 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>
#include <exception>
#include <vector>
#include <list>
#include <ctime>
#include <cctype>
#include <sstream>

# define RED	"\x1B[1;31m"
# define GREEN	"\x1B[1;32m"
# define RESET	"\x1B[0m"

class Timer
{
private:
	std::clock_t	_start_time;
	std::clock_t	_finish_time;

public:
	Timer();
	~Timer();
	Timer(const Timer& time);
	Timer&	operator=(const Timer& time);

	/* Methods */

	std::string		getTime() const;
	std::clock_t	getStartTime() const;
	std::clock_t	getFinishTime() const;
	void			start();
	void			stop();
};

template<typename Container = std::vector<int> >
class PmergeMe
{
private:
	void	_containerCheckers(const Container& container);

public:
	PmergeMe();
	~PmergeMe();
	PmergeMe(const PmergeMe& pmerg);
	PmergeMe& 	operator=(const PmergeMe& pmerg);

	/* Methods */

	void	sort(const int argc, const char** argv);

	class Exception : public std::exception
	{
		private:
			std::string	_message;
		public:
			Exception(std::string message): _message(message) {};
			virtual	~Exception() throw() {};

		const char*	what() const throw()
		{
			return (_message.c_str());
		}
	};
};

/* Aux functions */
void		deleteChArray(char*** array);
char**		split(const std::string& str, const std::size_t ch_count);
std::string	trim(const std::string& str);
bool		isNumber(const std::string& str);

/* Templates */
template<typename Container>
PmergeMe<Container>::PmergeMe() {}
template<typename Container>
PmergeMe<Container>::~PmergeMe() {}
template<typename Container>
PmergeMe<Container>::PmergeMe(const PmergeMe& pmerg)
{
	*this = pmerg;
}
template<typename Container>
PmergeMe<Container>&	PmergeMe<Container>::operator=(const PmergeMe& pmerg)
{
	(void)pmerg;
	return (*this);
}

template<typename Container>
std::string	toString(const Container& c)
{
	typename Container::const_iterator	it;
	typename Container::const_iterator	it_end = c.end();
	std::string	str;

	if (!c.empty())
	{
		std::advance(it_end, -1);
		for (it = c.begin(); it != it_end; it++)
			str.append(std::to_string(*it) + ' ');
		str.append(std::to_string(*it));
	}
	return (str);
}

template<typename Container>
Container	convertChArray(const int argc, const char** argv)
{
	Container		c;
	std::size_t		ch_count;
	std::string		buffer;
	char** 			ptr = (char**)argv + 1;
	char** 			array_ptr = NULL;
	int 			num = 0;
	std::string		trimmed;

	if (argc == 2)
	{
		buffer = argv[1];
		ch_count = std::count(buffer.begin(), buffer.end(), ' ');
		if (ch_count > 0)
		{
			ptr = split(buffer, ch_count);
			array_ptr = ptr;
		}
	}
	while (*ptr)
	{
		trimmed = trim(*ptr);
		if (!trimmed.empty())
		{
			if (!isNumber(trimmed))
				throw PmergeMe<>::Exception("Not a number");
			num = std::stoi(trimmed);
			c.insert(c.end(), num);
		}
		++ptr;
	}
	if (array_ptr)
		deleteChArray(&array_ptr);
	return (c);
}

template<>
std::string	convertChArray<std::string>(const int argc, const char** argv);

template<typename Container>
void	_Jsort(Container& c)
{
	std::size_t		mid_point;
	Container		_left;
	Container		_right;
	int				temp = INT_MAX;

	/* Make even */
	if (c.size()%2 != 0)
	{
		temp = c.at(c.size() - 1);
		c.pop_back();
	}
	mid_point = c.size() / 2;
	/* Divide */
	if (mid_point > 1)
	{
		_left.assign(c.begin(), c.begin() + mid_point);
		_Jsort(_left);
		_right.assign(c.begin() + mid_point, c.end());
		_Jsort(_right);
	}
	else if (!c.empty() && (c.at(0) > c.at(1)))
		std::swap(c.at(0), c.at(1));
	if (!_left.empty() && !_right.empty())
	{
		c.clear();
		if (_left.at(0) < _right.at(0))
			std::merge(_left.begin(), _left.end(), _right.begin(), _right.end(), std::back_inserter(c));
		else
			std::merge(_right.begin(), _right.end(), _left.begin(), _left.end(), std::back_inserter(c));
	}
	if (temp != INT_MAX)
		c.insert(
			std::upper_bound(c.begin(), c.end(), temp),
			temp
		);
}

template<>
void	_Jsort<std::list<int> >(std::list<int>& lst);

template<typename Container>
void	PmergeMe<Container>::_containerCheckers(const Container& container)
{
	typename	Container::const_iterator	it;
	typename	Container::const_iterator	tmp_it;
	int			value;
	std::size_t	index;

	for (it = container.begin(); it != container.end(); it++)
	{
		value = *it;
		index = std::distance(container.begin(), it);
		tmp_it = container.begin();
		std::advance(tmp_it, index + 1);
		if (index && std::find(tmp_it, container.end(), value) != container.end())
			throw PmergeMe::Exception("Duplicated symbols");
		if (value < 0)
			throw PmergeMe::Exception("Negative number");
		if (value < -std::numeric_limits<int>::max() || value > std::numeric_limits<int>::max())
			throw PmergeMe::Exception("Out of range");
	}
}

template<typename Container>
void	PmergeMe<Container>::sort(const int argc, const char** argv)
{
	Timer				timer;
	std::stringstream	ss;
	Container			_container;
	std::string			_container_name = typeid(Container).name();

	ss << "Before: " << convertChArray<std::string>(argc, argv) << std::endl;
	timer.start();
	_container = convertChArray<Container>(argc, argv);
	_containerCheckers(_container);
	_Jsort(_container);
	timer.stop();
	ss << "After: " << toString<Container>(_container) << std::endl;
	ss << GREEN << "Time to process a range of "
		<< _container.size() << " elements with std::"
		<< _container_name.substr(8, _container_name.length() - 29) << " : " << timer.getTime() << " us" << RESET << std::endl;
	std::cout << ss.str();
}
