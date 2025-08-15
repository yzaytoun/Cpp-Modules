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

void RPN::_compute(const RPN::CHtype type)
{
	int	num_1 = fetchValue();
	int num_2 = fetchValue();

	switch (type)
	{
		case MULTIPLY:
			_stack.push(num_2 * num_1);
			break;
		case DIVIDE:
			_stack.push(num_2 / num_1);
			break;
		case ADD:
			_stack.push(num_2 + num_1);
			break;
		case SUB:
			_stack.push(num_2 - num_1);
			break;
		default:
			break;
	}
}

void	RPN::_parse(const std::string args)
{
	std::string::const_iterator	it;
	RPN::CHtype	_type;
	RPN::CHtype	_lasttype;

	for (it = args.begin(); it != args.end(); it++)
	{	
		_type = _identify(*it);
		if (_type == _lasttype || _type == MAX_CHTYPE)
			throw RPN::Exception("Unidentified symbol");
		if (_type == NUMBER)
			_stack.push(*it - '0');
		else if (_type != MAX_CHTYPE && _type != SPACE)
			_compute(_type);
		_lasttype = _type;
	}
}

int	RPN::fetchValue(void)
{
	int num;

	if (!_stack.empty())
	{
		num = _stack.top();
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
