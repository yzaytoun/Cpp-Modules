/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 13:29:49 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/10/26 15:42:50 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const std::string args)
{
	try
	{
		_parse(args);
		_is_valid_input = true;
	}
	catch(const std::exception& e)
	{
		_is_valid_input = false;
		std::cerr << RED "Error: " RESET << e.what() << '\n';
	}
}

RPN::RPN(const RPN& r)
{
	*this = r;
}

RPN::~RPN() {}

RPN&	RPN::operator=(const RPN& r)
{
	if (this != &r)
		this->_stack = r.getStack();
	return (*this);
}

/* Methods */
std::stack<int>	RPN::getStack(void) const
{
	return (_stack);
}

RPN::CHtype	RPN::_identify(const int ch)
{
	CHtype	_type = MAX_CHTYPE;

	switch (ch)
	{
	case '*': _type = RPN::MULTIPLY; 	break;
	case '+': _type = RPN::ADD; 		break;
	case '/': _type = RPN::DIVIDE; 		break;
	case '-': _type = RPN::SUB; 		break;
	case ' ': _type = RPN::SPACE; 		break;
	default:
		if (isdigit(ch))
			_type = RPN::NUMBER;
		break;
	}

	return (_type);
}

void	RPN::_parse(const std::string args)
{
	std::string::const_iterator	it;
	std::string	errmsg;
	RPN::CHtype	_type = RPN::MAX_CHTYPE;
	RPN::CHtype	_last_type = RPN::MAX_CHTYPE;

	for (it = args.begin(); it != args.end(); it++)
	{	
		_type = _identify(*it);
		if (_type == _last_type)
			throw RPN::Exception("Repeated symbol");
		switch (_type)
		{
		case NUMBER:
			_stack.push(*it - '0');
			if (_stack.size() == 2)
				reverseStack();
			break;
		case MULTIPLY:
			_stack.push(getValue() * getValue());
			break;
		case DIVIDE:
			_stack.push(getValue() / getValue());
			break;
		case ADD:
			_stack.push(getValue() + getValue());
			break;
		case SUB:
			_stack.push(getValue() - getValue());
			break;
		case SPACE:
			break;
		default:
			errmsg = "Invalid input at -> ";
			throw RPN::Exception(errmsg + *it);
			break;
		}
		_last_type = _type;
	}
}

int	RPN::getValue(void)
{
	int num = -1;
	if (!_stack.empty())
	{
		num = _stack.top();
		std::cout << "num -> " << num << std::endl;
		_stack.pop();
	}
	else
		throw RPN::Exception("Forbbiden operation");
	return (num);
}

void	RPN::print()
{
	std::cout << _stack.top() << std::endl;
}

bool	RPN::isValid()
{
	return (_is_valid_input);
}

void	RPN::reverseStack()
{
	std::stack<int>	temp_stack;

	while (!_stack.empty())
	{
		temp_stack.push(_stack.top());
		_stack.pop();
	}
	_stack = temp_stack;
}
