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

PmergeMe::PmergeMe() {}

PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& pmerg)
{
	*this = pmerg;
}

PmergeMe&   PmergeMe::operator=(const PmergeMe& pmerg)
{
	if (this != &pmerg)
	{
		this->_list_container = pmerg.getList();
		this->_vec_container = pmerg.getVector();
	}
	return (*this);
}

std::vector<int>	PmergeMe::getVector() const
{
	return (_vec_container);
}

std::list<int>		PmergeMe::getList() const
{
	return (_list_container);
}

std::string	compressChArray(const char** argv)
{
	std::string	str;
	const char** ptr = argv;

	while (*ptr)
	{
		str.append(*ptr);
		str.append(" ");
		++ptr;
	} 
	return (str);
}

std::vector<int>	ChArrayToVector(const char** argv)
{
	std::vector<int>	vec;
	const char** ptr = argv;
	int	num = 0;

	while (*ptr)
	{
		num = std::stoi(*ptr);
		vec.push_back(num);
		++ptr;
	}
	return (vec);
}

std::list<int>	ChArrayToList(const char** argv)
{
	std::list<int>	lst;
	const char** ptr = argv;
	int	num = 0;
	
	while (*ptr)
	{
		num = std::stoi(*ptr);
		lst.push_back(num);
		++ptr;
	}
	return (lst);
}

void	_JsortVector(std::vector<int>& vec)
{
	std::size_t	mid_point = vec.size()/2;
	std::vector<int>	left_vector;
	std::vector<int>	right_vector;

	if (mid_point > 1)
	{
		left_vector.assign(vec.begin(), vec.begin() + mid_point);
		_JsortVector(left_vector);
		right_vector.assign(vec.begin() + mid_point, vec.end());
		_JsortVector(right_vector);
	}
	if (left_vector.at(0) > right_vector.at(0))
		left_vector.insert(left_vector.end(), right_vector.begin(), right_vector.end());
	vec = left_vector;
}

void	_JsortList(std::list<int>& lst)
{
	(void)lst;
}

std::string	vecToString(const std::vector<int>& vec)
{
	std::vector<int>::const_iterator	it;
	std::string	str;

	for (it = vec.begin(); it != vec.end() - 1; it++)
		str.append(std::to_string(vec.at(*it)) + ' ');
	str.append(std::to_string(vec.at(*it)));
	return (str);
}

void	PmergeMe::sort(const char** argv)
{
	Timer				vec_timer;
	Timer				list_timer;
	std::stringstream	ss;

	ss << "Before: " << compressChArray(argv);
	
	/* Vector */
	vec_timer.start();
	_vec_container = ChArrayToVector(argv);
	_JsortVector(_vec_container);
	vec_timer.stop();
	
	/* List */
	list_timer.start();
	_list_container = ChArrayToList(argv);
	_JsortList(_list_container);
	list_timer.stop();
	
	ss << "After: " << vecToString(_vec_container);
	ss << "Time to process a range of " << _vec_container.size() << " elements with std::vector : " <<  vec_timer.getTime() << " us" << std::endl;
	ss << "Time to process a range of " << _list_container.size() <<  "elements with std::list : " <<  list_timer.getTime() << " us" << std::endl;
	std::cout << ss.str();
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
	std::time(&_start_time);
}

void Timer::stop()
{
	std::time(&_finish_time);
}

std::string Timer::getTime() const
{
	return (std::to_string(std::difftime(_finish_time, _start_time)));
}

std::time_t Timer::getStartTime() const
{
	return (_start_time);
}

std::time_t Timer::getFinishTime() const
{
	return (_finish_time);
}
