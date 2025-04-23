/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 13:31:01 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/10/26 15:43:54 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

typedef	struct s_scalar
{
	char		_char;
	int			_int;
	float		_float;
	double		_double;
} t_scalar;

class ScalarConverter
{
public:
	enum Type
	{
		CHAR,
		INTEGER,
		FLOAT,
		DOUBLE,
		INF,
		MAX_SCALAR
	};
private:
	ScalarConverter();
	ScalarConverter(const ScalarConverter& converter);
	ScalarConverter&	operator=(const ScalarConverter& converter);
	
public:
	virtual	~ScalarConverter() = 0;
	static t_scalar	convert(const std::string value);
};

std::ostream&	operator>>(std::ostream& out, const t_scalar sca);