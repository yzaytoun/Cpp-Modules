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

std::string	toChar(const std::string value)
{
	char		c = value.at(0);
	std::string	result;

	if (value.length() > 1
		|| (c > std::numeric_limits<char>::max() || c < std::numeric_limits<char>::min()))
		result = "impossible";
	else if (!std::isprint(c) || std::isdigit(c))
		result = "Non dispalyable";
	else
		result = c;
	return (result);
}

std::string	toInteger(const std::string value, ScalarConverter::Type type)
{
	long				num = -1;
	std::stringstream	result;

	try
	{
		num = std::stol(value);
	}
	catch(const std::exception& e)
	{
		result << "impossible";
	}
	if (result.str().empty())
	{
		if (num > std::numeric_limits<int>::max() || num < std::numeric_limits<int>::min())
			result << "impossible";
		else if (type == ScalarConverter::CHAR)
			result << static_cast<int>(value.at(0));
		else
			result << num;
	}
	return (result.str());
}

std::string	toFloat(const std::string value, ScalarConverter::Type type)
{
	float				num = -1;
	std::stringstream	result;

	try
	{
		num = std::stof(value);
	}
	catch(const std::exception& e)
	{
		result << "impossible";
	}
	if (result.str().empty())
	{
		if (num > std::numeric_limits<float>::max() || num < std::numeric_limits<float>::min())
			result << "impossible";
		else if (type == ScalarConverter::CHAR)
			result << static_cast<float>(value.at(0));
		else if (isInfinity(value))
			result << value;
		else
			result << num;
		if (result.str().compare("impossible") != 0 && !endsWith(result.str(), "f"))
				result << "f";
	}
	return (result.str());
}

std::string	toDouble(const std::string value, ScalarConverter::Type type)
{
	double				num = std::stod(value);
	std::stringstream	result;

	try
	{
		num = std::stof(value);
	}
	catch(const std::exception& e)
	{
		result << "impossible";
	}
	if (result.str().empty())
	{
		if (num > std::numeric_limits<double>::max() || num < std::numeric_limits<double>::min())
			result << "impossible";
		else if (type == ScalarConverter::CHAR)
			result << static_cast<double>(value.at(0));
		else
			result << num;
		if (result.str().compare("impossible") != 0)
		{
			if (!containsSubStr(result.str(), "."))
				result << ".0";
			if (!endsWith(result.str(), "f"))
				result << "f";
		}
	}
	return (result.str());
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
			if (!is_number && val.at(i) == '.')
				++point_count;
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
				++point_count;
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
		if ((is_number && val.at(i) != 'f') || (f_count == 0))
			is_number = false;
	}
	return (is_number);
}

bool	isChar(const std::string value)
{
	return (value.length() == 1 && std::isprint(value.at(0)));
}

ScalarConverter::Type   getDataType(const std::string value)
{
	ScalarConverter::Type	datatype = ScalarConverter::SCALAR_MAX;
	bool	(*typefunc[4])(std::string) = {
		isChar,
		isInteger,
		isFloat,
		isDouble
	};

	for (int i = 0; i < ScalarConverter::SCALAR_MAX; i++)
	{
		if (typefunc[i](value))
		{
			datatype = static_cast<ScalarConverter::Type>(i);
			break;
		}
	}
	return (datatype);
}

std::string	cutString(const std::string str, char c)
{
	std::string	new_str;
	std::size_t	pos = str.find(c);

	if (pos != std::string::npos)
		new_str = str.substr(0, pos);
	return (new_str);
}

/* --------- convert --------- */

std::string	ScalarConverter::convert(const std::string value)
{
	std::string				cleaned_value = cutString(value, '\n');
	ScalarConverter::Type	type = getDataType(cleaned_value);
	std::stringstream		ss;

	if (type == ScalarConverter::CHAR || type == ScalarConverter::INTEGER
		|| type == ScalarConverter::DOUBLE || type == ScalarConverter::FLOAT)
	{
		ss 	<< toChar(cleaned_value)
			<< "\n"
			<< toInteger(cleaned_value, type)
			<< "\n"
			<< toFloat(cleaned_value, type)
			<< "\n"
			<< toDouble(cleaned_value, type)
			<< "\n";
	}
	else
		ss << "Cannot handle this value type!!";
	return (ss.str());
}
