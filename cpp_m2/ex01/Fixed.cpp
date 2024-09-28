/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 16:54:14 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/09/28 20:25:08 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void)
{
	this->_fixed_point = 0;
	print("Default constructor called", 1);
}

Fixed::Fixed(const Fixed& f) : _fixed_point(f.getRawBits())
{
	print("Copy constructor called", 1);
}

Fixed::Fixed(const int num) : _fixed_point(num)
{
}

Fixed::Fixed(const float num)
{
	this->_fixed_point = roundf(num);
	//to from int to float
}

Fixed::~Fixed(void)
{
	print("Destructor called", 1);
}

Fixed&	Fixed::operator=(const Fixed &f)
{
	print("Copy assignment operator called", 1);
	if (this != &f)
		this->_fixed_point = f.getRawBits();
	return (*this);
}

std::ostream&	operator<<(std::ostream &out, const Fixed &f)
{
	out << f._fixed_point << "." << f._fraction;
	return (out);
}

int	Fixed::getRawBits(void) const
{
	print("getRawBits member function called", 1);
	return (this->_fixed_point);
}

void	Fixed::setRawBits(int const raw)
{
	this->_fixed_point = raw;
}

float	Fixed::toFloat(void) const
{
	return ()
}

int		Fixed::toInt(void) const
{
	
}