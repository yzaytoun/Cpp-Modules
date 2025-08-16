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
#include <sstream>

# define RED	"\x1B[1;31m"
# define RESET	"\x1B[0m"

class Timer
{
private:
	std::time_t	_start_time;
	std::time_t	_finish_time;

public:
	Timer();
	~Timer();
	Timer(const Timer& time);
	Timer&	operator=(const Timer& time);

	/* Methods */

	std::string		getTime() const;
	std::time_t		getStartTime() const;
	std::time_t		getFinishTime() const;
	void			start();
	void			stop();
};

class PmergeMe
{
private:
	std::vector<int>	_vec_container;
	std::list<int>		_list_container;

public:
	PmergeMe();
	~PmergeMe();
	PmergeMe(const PmergeMe& pmerg);
	PmergeMe& 	operator=(const PmergeMe& pmerg);

	/* Methods */

	std::vector<int>	getVector() const;
	std::list<int>		getList() const;
	void				sort(const char** argv);

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
