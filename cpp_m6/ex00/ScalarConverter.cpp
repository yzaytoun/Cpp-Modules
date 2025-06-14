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

std::string	toChar(const std::string value, bool is_explicit = true)
{
	char		c = value.at(0);
	std::string	result;

	if (c > std::numeric_limits<char>::max() || c < std::numeric_limits<char>::min())
		result = "impossible";
	else
		result = value;
	return (result);
}

std::string	toInteger(const std::string value, bool is_explicit = true)
{
	int	num = std::stoi(value);
	std::string	result;

	if (num > std::numeric_limits<int>::max() || num < std::numeric_limits<int>::min())
		result = "impossible";
	else
		result = value;
	return (result);
}

std::string	toFloat(const std::string value, bool is_explicit = true)
{
	float	num = std::stof(value);
	std::string	result;

	if (num > std::numeric_limits<float>::max() || num < std::numeric_limits<float>::min())
		result = "impossible";
	else
		result = value;
	if (!endsWith(result, "f"))
		result.append("f");
	return (result);
}

std::string	toDouble(const std::string value, bool is_explicit = true)
{
	double	num = std::stod(value);
	std::string	result;

	if (num > std::numeric_limits<double>::max() || num < std::numeric_limits<double>::min())
		result = "impossible";
	else
		result = value;
	return (result);
}

t_scalar	toInfinity(std::string value, bool is_explicit = true)
{
	t_scalar	sca;

	sca._char = static_cast<char>(value.at(0));
	sca._int = static_cast<int>(value);
	sca._double = static_cast<double>(value);
	sca._float = static_cast<float>(value);
	return (sca);
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

bool	isInfinity(const std::string val)
{
	bool				is_inf = false;
	const std::string	constants[5] = {"-inff", "+inff", "-inf", "+inf", "nan"};
	int					i = 0;

	while (i < 5)
	{
		if (val.compare(constants[i]) == 0)
		{
			is_inf = true;
			break;
		}
		++i;
	}
	return (is_inf);
}

int	charCount(const std::string str, int chr)
{
	int		count = 0;
	size_t	i = 0;

	while (i < str.size())
	{
		if (str.at(i) == chr)
			++count;
		++i;
	}
	return (count);
}

bool	isInteger(const std::string val)
{
	bool	is_number = false;
	std::size_t	i = 0;

	if (!val.empty())
	{
		while (i < val.size())
		{
			is_number = std::isdigit(val.at(i));
			if (!is_number)
				break;
			++i;
		}
	}
	return (is_number);
}

bool	isDouble(const std::string val)
{
	bool		is_number = false;
	int			point_count = 0;
	std::size_t	i = 0;

	if (!val.empty())
	{
		while (i < val.size())
		{
			is_number = std::isdigit(val.at(i));
			if (!is_number && val.at(i) == '.' && !point_count)
			{
				++point_count;
				continue;
			}
			else if (!is_number)
				break;
			++i;
		}
	}
	return (is_number);
}

bool	isFloat(const std::string val)
{
	bool		is_number = false;
	int			point_count = 0;
	std::size_t	i = 0;

	
	if (!val.empty())
	{
		while (i < val.size() - 1)
		{
			is_number = std::isdigit(val.at(i));
			if (!is_number && val.at(i) == '.' && !point_count)
			{
				++point_count;
				continue;
			}
			else if (!is_number)
				break;
			++i;
		}
		if (is_number && val.at(i) != 'f')
			is_number = false;
	}
	return (is_number);
}

ScalarConverter::Type   getDataType(const std::string value)
{
	ScalarConverter::Type	datatype = ScalarConverter::SCALAR_NULL;

	if (value.length() == 1 && std::isprint(value.at(0)))
		datatype = ScalarConverter::CHAR;
	else if (isFloat(value))
		datatype = ScalarConverter::FLOAT;
	else if (isDouble(value))
		datatype = ScalarConverter::DOUBLE;
	else if (isInteger(value))
		datatype = ScalarConverter::INTEGER;
	else if (isInfinity(value))
		datatype = ScalarConverter::INF;
	return (datatype);
}

/* --------- convert --------- */

t_scalar	ScalarConverter::convert(const std::string value)
{
	t_scalar	sca;

	switch (getDataType(value))
	{
	case ScalarConverter::CHAR:
	{
		sca._char = toChar(value, false);
		sca._int = toInteger(value);
		sca._double = toDouble(value);
		sca._float = toFloat(value);
		break;
	}
	case ScalarConverter::INTEGER:
	{
		sca._char = toChar(value);
		sca._int = toInteger(value, false);
		sca._double = toDouble(value);
		sca._float = toFloat(value);
		break;
	}
	case ScalarConverter::DOUBLE:
	{
		sca._char = toChar(value);
		sca._int = toInteger(value);
		sca._double = toDouble(value, false);
		sca._float = toFloat(value);
		break;
	}
	case ScalarConverter::FLOAT:
	{
		sca._char = toChar(value);
		sca._int = toInteger(value);
		sca._double = toDouble(value);
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
