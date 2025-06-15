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

/*-------- Converters ---------*/

std::string	toChar(const std::string value, bool is_explicit = true)
{
	char		c = value.at(0);
	std::string	result;

	if (is_explicit)
		result = (char)value.at(0);
	else if (c > std::numeric_limits<char>::max() || c < std::numeric_limits<char>::min())
		result = "impossible";
	else if (std::isdigit(c))
		result = "Non dispalyable";
	else
		result = value;
	return (result);
}

std::string	toInteger(const std::string value)
{
	int	num = std::stoi(value);
	std::string	result;

	if (num > std::numeric_limits<int>::max() || num < std::numeric_limits<int>::min())
		result = "impossible";
	else
		result = value;
	return (result);
}

std::string	toFloat(const std::string value)
{
	float	num = std::stof(value);
	std::string	result;

	if (num > std::numeric_limits<float>::max() || num < std::numeric_limits<float>::min())
		result = "impossible";
	else if (isInfinity(value))
		result = value + "f";
	else
		result = value;
	if (!endsWith(result, "f"))
		result.append("f");
	return (result);
}

std::string	toDouble(const std::string value)
{
	double	num = std::stod(value);
	std::string	result;

	if (num > std::numeric_limits<double>::max() || num < std::numeric_limits<double>::min())
		result = "impossible";
	else
		result = value;
	return (result);
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
			if (point_count > 1)
			{
				is_number = false;
				break;
			}
			++i;
		}
	}
	return (is_number);
}

bool	isFloat(const std::string val)
{
	bool		is_number = false;
	int			point_count = 0;
	int			f_count = 0;
	std::size_t	i = 0;

	
	if (!val.empty())
	{
		while (i < val.size() - 1)
		{
			is_number = std::isdigit(val.at(i));
			if (!is_number && val.at(i) == '.')
			{
				++point_count;
				continue;
			}
			else if (!is_number && val.at(i) == 'f')
				++f_count;
			else if (!is_number)
				break;
			if (point_count > 1 || f_count > 0)
			{
				is_number = false;
				break;
			}
			++i;
		}
		if (is_number && val.at(i) != 'f')
			is_number = false;
	}
	return (is_number);
}

ScalarConverter::Type   getDataType(const std::string value)
{
	ScalarConverter::Type	datatype = ScalarConverter::SCALAR_MAX;

	if (value.length() == 1 && std::isprint(value.at(0)))
		datatype = ScalarConverter::CHAR;
	else if (isFloat(value))
		datatype = ScalarConverter::FLOAT;
	else if (isDouble(value))
		datatype = ScalarConverter::DOUBLE;
	else if (isInteger(value))
		datatype = ScalarConverter::INTEGER;
	return (datatype);
}

/* --------- convert --------- */

std::string	ScalarConverter::convert(const std::string value)
{
	bool	config[SCALAR_MAX] = {false, false, false, false};
	ScalarConverter::Type	type = getDataType(value);
	std::stringstream	ss;

	if (type == ScalarConverter::CHAR || ScalarConverter::INTEGER || ScalarConverter::DOUBLE || ScalarConverter::FLOAT)
	{
		ss 	<< toChar(value, type) 
			<< "\n"
			<< toInteger(value, type)
			<< "\n"
			<< toFloat(value, type)
			<< "\n"
			<< toDouble(value, type)
			<< "\n";
	}
	else
		ss << "Cannot handle this value type!!";
	return (ss.str());
}
