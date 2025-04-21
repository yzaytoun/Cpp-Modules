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

std::string	toChar(const std::string value)
{
    char            c = -1;
    std::string     output;

    if (value.length() == 1)
    {
		c = value.at(0);
        if (c >= 32 && c <= 127)
			output = c;
    }
	else
		output = "impossible!";
    return (output);
}

int    toInteger(const std::string value)
{
    return (std::atoi(value.c_str()));
}

float    toFloat(const std::string value)
{
    return (std::atof(value.c_str()));
}

double    toDouble(const std::string value)
{
    return (std::stod(value.c_str()));
}

std::string	getDataType(const std::string value)
{
	std::string datatype;

	if (value.length() == 1 && isAlpha(value.at(0)))
		datatype = "char";
	else if (containsSubStr(value, "f"))
		datatype = "float";
	else if (containsSubStr(value, "."))
		datatype = "double";
	else if (isDigit(value))
		datatype = "integer";
	return (datatype);
}

t_scalar    ScalarConverter::convert(const std::string value)
{
    t_scalar    sca;

	std::cout << getDataType(value) << std::endl;
    sca.c = toChar(value);
    sca.i = toInteger(value);
    sca.f = toDouble(value);
    sca.d = toFloat(value);
    return (sca);
}
