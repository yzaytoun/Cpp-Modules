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

/* Private constructors */
ScalarConverter::ScalarConverter() {}
ScalarConverter::~ScalarConverter() {}

ScalarConverter::ScalarConverter(ScalarConverter& scala)
{
	*this = scala;
}

ScalarConverter&	ScalarConverter::operator=(ScalarConverter& scala)
{
	(void)scala;
	return (*this);	
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

bool	isSign(int ch)
{
	return (ch == '-' || ch == '+');
}

bool	isInfinity(const std::string val)
{
	bool				is_inf = false;
	std::string			val_to_compare = val;
	const std::string	constants[6] = {"inff", "inf", "nan", "nanf"};
	int					i = 0;

	if (isSign(val[0]))
		val_to_compare.erase(0,1);
	while (i < 6)
	{
		if (val_to_compare == constants[i])
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

	if (type == ScalarConverter::CHAR)
		result << static_cast<int>(value.at(0));
	else
	{
		try
		{
			num = std::stoi(value);
		}
		catch(const std::exception& e)
		{
			result << "impossible";
		}
		if (result.str().empty())
		{
			if (num > std::numeric_limits<int>::max() || num < std::numeric_limits<int>::min())
				result << "impossible";
			else
				result << num;
		}
	}
	return (result.str());
}

std::string	toFloat(const std::string value, ScalarConverter::Type type)
{
	float				num = -1;
	std::stringstream	result;

	if (type == ScalarConverter::CHAR)
		result << static_cast<float>(value.at(0));
	else if (type == ScalarConverter::INF)
	{
		if (!endsWith(value, "ff") && !startsWith(value, "nan"))
			result << value << "f";
		else
			result << value;
	}
	else
	{
		try
		{
			num = std::strtof(value.c_str(), NULL);
		}
		catch(const std::exception& e)
		{
			result << "impossible";
		}
		if (result.str().empty())
		{
			if (num > std::numeric_limits<float>::max() || num < -std::numeric_limits<float>::max())
				result << "impossible";
			else
				result << num;
		}
	}
	if (type != ScalarConverter::INF && !containsSubStr(result.str(), "."))
		result << ".0";
	if (result.str().compare("impossible") != 0 && !endsWith(result.str(), "f"))
		result << "f";
	return (result.str());
}

std::string	toDouble(const std::string value, ScalarConverter::Type type)
{
	double				num = -1;
	std::stringstream	result;

	if (type == ScalarConverter::CHAR)
		result << static_cast<double>(value.at(0));
	else if (type == ScalarConverter::INF)
	{
		if (endsWith(value,"f") && !endsWith(value, "inf"))
			result << value.substr(0, value.length() - 1);
		else
			result << value;
	}
	else
	{
		try
		{
			num = std::strtod(value.c_str(), NULL);
		}
		catch(const std::exception& e)
		{
			result << "impossible";
		}
		if (result.str().empty())
		{
			if (num > std::numeric_limits<double>::max() || num < -std::numeric_limits<double>::max())
				result << "impossible";
			else
				result << num;
		}
	}
	if (type != ScalarConverter::INF && result.str() != "impossible" && !containsSubStr(result.str(), "."))
		result << ".0";
	return (result.str());
}

bool	isInteger(const std::string val)
{
	bool	is_number = false;
	short	sign_count = 0;
	std::size_t	i = 0;

	if (!val.empty())
	{
		while (i < val.size())
		{
			is_number = std::isdigit(val.at(i));
			if (!is_number && isSign(val.at(i)) && !sign_count)
			{
				++sign_count;
				++i;
				continue;
			}
			else if (!is_number)
				break;
			++i;
		}
	}
	return (is_number);
}

bool	isDouble(const std::string val)
{
	bool		is_number = false;
	short		sign_count = 0;
	int			point_count = 0;
	std::size_t	i = 0;

	if (!val.empty())
	{
		while (i < val.size())
		{
			is_number = std::isdigit(val.at(i));
			if (!is_number && val.at(i) == '.')
				++point_count;
			else if (!is_number && isSign(val.at(i)))
				++sign_count;
			else if (!is_number)
				break;
			if (point_count > 1 || sign_count > 1)
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
	short		sign_count = 0;
	std::size_t	i = 0;

	
	if (!val.empty())
	{
		while (i < val.size() - 1)
		{
			is_number = std::isdigit(val.at(i));
			if (!is_number && val.at(i) == '.')
				++point_count;
			else if (!is_number && isSign(val.at(i)))
				++sign_count;
			else if (!is_number && val.at(i) == 'f')
				++f_count;
			else if (!is_number)
				break;
			if (point_count > 1 || f_count > 0 || sign_count > 0)
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
	return (value.length() == 1 && std::isprint(value.at(0)) && !std::isdigit(value.at(0)));
}

ScalarConverter::Type   getDataType(const std::string value)
{
	ScalarConverter::Type	datatype = ScalarConverter::SCALAR_MAX;
	bool	(*typefunc[5])(std::string) = {
		isChar,
		isInteger,
		isFloat,
		isDouble,
		isInfinity
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

	if (type != ScalarConverter::SCALAR_MAX)
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
