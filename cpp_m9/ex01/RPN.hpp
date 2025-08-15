/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp  			                                :+:      :+:    :+:   */
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
#include <iterator>
#include <stack>

# define RED	"\x1B[1;31m"
# define RESET	"\x1B[0m"

class RPN
{
private:
	enum CHtype
	{
		MULTIPLY,
		DIVIDE,
		ADD,
		SUB,
		NUMBER,
		SPACE,
		MAX_CHTYPE
	};

	std::stack<int>		_stack;
	bool				_is_valid_input;

	void		_compute(const CHtype type);
	void		_parse(const std::string args);
	CHtype		_identify(const int ch);
public:
	RPN();
	RPN(const std::string args);
	~RPN();
	RPN(const RPN& r);
	RPN&	operator=(const RPN& r);

	/* Methods */
	std::stack<int>	getStack(void) const;
	int				fetchValue(void);
	void			print(void);
	bool			isValid(void);


	class Exception : public std::exception
	{
		private:
			std::string	_message;
		public:
			Exception(std::string message): _message(message) {};
			virtual~Exception() throw() {};

		const char*	what() const throw()
		{
			return (_message.c_str());
		}
	};
};
