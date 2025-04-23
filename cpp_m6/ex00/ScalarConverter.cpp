/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 13:29:49 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/10/26 15:42:50 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::~ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& converter)
{
	(void)converter;
}

ScalarConverter&	ScalarConverter::operator=(const ScalarConverter& converter)
{
	(void)converter;
	return (*this);
}

/*-------- Converters ---------*/

char	toChar(const std::string value, bool is_explicit = true)
{
	char	c;

	
	return (c);
}

int	toInteger(const std::string value, bool is_explicit = true)
{
	int	num;

	
	return (num);
}

float	toFloat(const std::string value, bool is_explicit = true)
{
	float	num;


	return (num);
}

double	toDouble(const std::string value, bool is_explicit = true)
{
	double	num;

	return (num);
}

t_scalar	toInfinity(const std::string value, bool is_explicit = true)
{
	t_scalar	sca;

	sca._char = static_cast<char>(value.at(0));
	sca._int = static_cast<int>(value.at(0));
	sca._double = static_cast<double>(value.at(0));
	sca._float = static_cast<float>(value.at(0));
	return (sca);
}

/*-------- Checkers ---------*/

bool	isChar(const std::string val)
{
	bool	is_char = false;

	return (is_char);
}

bool	isInteger(const std::string val)
{
	bool	is_int = false;
	
	return (is_int);
}

bool	isDouble(const std::string val)
{
	bool	is_double = false;
	
	return (is_double);
	
}

bool	isFloat(const std::string val)
{
	bool	is_float = false;
	
	return (is_float);
	
}

bool	isInfinity(const std::string val)
{
	bool	is_inf = false;
	
	return (is_inf);

}

/*-------- AUX ---------*/

bool    containsSubStr(const std::string str_to_search, const std::string value_to_find)
{
	std::size_t pos = str_to_search.find(value_to_find);

	if (pos != std::string::npos)
		return (true);
	return (false);
}

bool    endsWith(const std::string str_to_search, const std::string suffix)
{
	bool	ends_with = false;

	if (!str_to_search.empty() && str_to_search.length() >= suffix.length())
	{
		if (str_to_search.compare(str_to_search.length() - suffix.length(), suffix.length(), suffix) == 0)
			ends_with = true;
	}
	return (ends_with);
}

bool    startsWith(const std::string str_to_search, const std::string prefix)
{
	bool	starts_with = false;

	if (!str_to_search.empty() && str_to_search.length() >= prefix.length())
	{
		if (str_to_search.compare(0, prefix.length(), prefix) == 0)
			starts_with = true;
	}
	return (starts_with);
}

ScalarConverter::Type   getDataType(const std::string value)
{
	ScalarConverter::Type	datatype;

	if (isChar(value))
		datatype = ScalarConverter::CHAR;
	else if (isDouble(value))
		datatype = ScalarConverter::DOUBLE;
	else if (isFloat(value))
		datatype = ScalarConverter::FLOAT;
	else if (isInteger(value))
		datatype = ScalarConverter::INTEGER;
	else if (isInfinity(value))
		datatype = ScalarConverter::INF;
	return (datatype);
}

t_scalar	ScalarConverter::convert(const std::string value)
{
	t_scalar	sca;

	switch (getDataType(value))
	{
	case ScalarConverter::CHAR:
	{
		sca._char = toChar(value, false);
		sca._int = toInteger(value, true);
		sca._double = toDouble(value, true);
		sca._float = toFloat(value, true);
		break;
	}
	case ScalarConverter::INTEGER:
	{
		sca._char = toChar(value, true);
		sca._int = toInteger(value, false);
		sca._double = toDouble(value, true);
		sca._float = toFloat(value, true);
		break;
	}
	case ScalarConverter::DOUBLE:
	{
		sca._char = toChar(value, true);
		sca._int = toInteger(value, true);
		sca._double = toDouble(value, false);
		sca._float = toFloat(value, true);
		break;
	}
	case ScalarConverter::FLOAT:
	{
		sca._char = toChar(value, true);
		sca._int = toInteger(value, true);
		sca._double = toDouble(value, true);
		sca._float = toFloat(value, false);
		break;
	}
	case ScalarConverter::INF:
		sca = toInfinity(value);
		break;
	default:
		std::cerr << "Cannot handle this value type!!" << std::endl;
		break;
	}
	return (sca);
}
