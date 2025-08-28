/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 13:29:49 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/10/26 15:42:50 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

/*
   ----------  PmergeMe -------------
*/

template<>
void	_Jsort<std::list<int> >(std::list<int>& lst)
{
	std::size_t					mid_point;
	std::list<int>				_left;
	std::list<int>				_right;
	std::list<int>::iterator	it = lst.begin();
	int							temp = INT_MAX;

	/* Make even */
	if (lst.size()%2 != 0)
	{
		temp = lst.back();
		lst.pop_back();
	}
	mid_point = lst.size() / 2;
	/* Divide */
	if (mid_point > 1)
	{
		std::advance(it, mid_point);
		_left.assign(lst.begin(), it);
		_Jsort(_left);
		_right.assign(it, lst.end());
		_Jsort(_right);
	}
	else if (!lst.empty() && (lst.front() > lst.back()))
		std::swap(lst.front(), lst.back());
	if (!_left.empty() && !_right.empty())
	{
		lst.clear();
		if (_left.back() < _right.back())
			std::merge(_left.begin(), _left.end(), _right.begin(), _right.end(), std::back_inserter(lst));
		else
			std::merge(_right.begin(), _right.end(), _left.begin(), _left.end(), std::back_inserter(lst));
	}
	if (temp != INT_MAX)
		lst.insert(
			std::upper_bound(lst.begin(), lst.end(), temp),
			temp
		);
}

template<>
std::string	convertChArray<std::string>(const int argc, const char** argv)
{
	std::string		str;
	char** 			ptr = (char**)(argv + 1);
	char** 			array_ptr = NULL;
	std::size_t		ch_count;
	std::string		buffer;

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
	while (*(ptr + 1))
	{
		str.append(*ptr);
		str.append(" ");
		++ptr;
	}
	str.append(*ptr);
	if (array_ptr)
		deleteChArray(&array_ptr);
	return (str);
}

/* String & Char Array Functions */

void	deleteChArray(char*** array)
{
	if ((*array))
	{
		delete [] (*array);
		(*array) = NULL;
	}
}

char**	split(const std::string& str, const std::size_t ch_count)
{
	char**		new_charray = new char*[ch_count + 1];
	int			count = 0;
	std::size_t	start = 0;
	std::size_t	end = 0;

	while (end != std::string::npos)
	{
		end = str.find(' ', start);
		if (end != std::string::npos)
		{
			new_charray[count] = new char[end - start];
			if (new_charray[count])
			{
				str.copy(new_charray[count], end - start, start);
				new_charray[count][end - start] = '\0';
			}
			else
				break;
			++count;
			start = end + 1;
		}
		else if (start != std::string::npos)
		{
			new_charray[count] = new char[str.substr(start).length()];
			str.copy(new_charray[count], str.substr(start).length(), start);
			new_charray[count][str.substr(start).length()] = '\0';
		}
	}
	new_charray[ch_count + 1] = NULL;
	return (new_charray);
}

bool	_isspace(unsigned int c)
{
	return (std::isspace(c));
}

int	_isnotspace(unsigned int c)
{
	return !_isspace(c);
}
int	_isnotdigit(unsigned int c)
{
	return (!std::isdigit(c) && c != '-' && c != '+');
}

std::string	trim(const std::string& str)
{
	std::string::const_iterator	start_it;
	std::string::const_iterator	end_it;
	std::string	trimmed;

	start_it = std::find_if(str.begin(), str.end(), _isnotspace);
	end_it = std::find_if(start_it, str.end(), _isspace);
	if (start_it != str.end())
		trimmed = str.substr(
			std::distance(str.begin(), start_it),
			std::distance(str.begin(), end_it)
		);
	return (trimmed);
}

bool	isNumber(const std::string& str)
{
	return (std::find_if(str.begin(), str.end(), _isnotdigit) == str.end());
}

/*
   ----------  Timer -------------
*/

Timer::Timer() : _start_time(0), _finish_time(0) {}
Timer::~Timer() {}

Timer::Timer(const Timer& time) : _start_time(time.getStartTime()) , _finish_time(time.getFinishTime()) {}

Timer&  Timer::operator=(const Timer& time)
{
	if (this != &time)
	{
		this->_start_time = time.getStartTime();
		this->_finish_time = time.getFinishTime();
	}
	return (*this);
}

void    Timer::start()
{
	_start_time = clock();
}

void Timer::stop()
{
	_finish_time = clock();
}

std::string Timer::getTime() const
{
	return (std::to_string((double)((1000.0 * (_finish_time - _start_time) / CLOCKS_PER_SEC))));
}

std::clock_t Timer::getStartTime() const
{
	return (_start_time);
}

std::clock_t Timer::getFinishTime() const
{
	return (_finish_time);
}
