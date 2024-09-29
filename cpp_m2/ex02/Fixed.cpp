/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 16:54:14 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/09/29 16:27:25 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void) : _fixed_point(0)
{
	print("Default constructor called", 1);
}

Fixed::Fixed(const Fixed& f) : _fixed_point(f.getRawBits())
{
	print("Copy constructor called", 1);
}

Fixed::Fixed(const int num) : _fixed_point(num << _fraction)
{
}

Fixed::Fixed(const float num)
{
	this->_fixed_point = roundf(num * (1 << _fraction));
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
	out << f.toFloat();
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
	return (
		static_cast<float> (this->_fixed_point) / (1 << _fraction)
	);
}

int		Fixed::toInt(void) const
{
	return (
		static_cast<int> (this->_fixed_point >> _fraction)
	);
}

//https://github.com/mizvekov/fp/blob/master/fp/fp.hpp
Fixed&	operator<(const Fixed& f1, const Fixed& f2)
{
	
}
Fixed&	operator>(const Fixed& f1, const Fixed& f2)
{
	
}
Fixed&	operator<=(const Fixed& f1, const Fixed& f2)
{
	
}
Fixed&	operator>=(const Fixed& f1, const Fixed& f2)
{
	
}
Fixed&	operator==(const Fixed& f1, const Fixed& f2)
{
	
}
Fixed&	operator!=(const Fixed& f1, const Fixed& f2)
{
	
}

Fixed&	operator+(const Fixed& f1, const Fixed& f2)
{
	
}

Fixed&	operator-(const Fixed& f1, const Fixed& f2)
{
	
}

Fixed&	operator/(const Fixed& f1, const Fixed& f2)
{
	
}

Fixed&	operator*(const Fixed& f1, const Fixed& f2)
{
	
}

Fixed&	operator++(const Fixed& f)
{

}

Fixed&	operator--(const Fixed& f)
{

}

Fixed&	Fixed::min(const Fixed& f1, const Fixed& f2)
{
	
}

Fixed&	Fixed::min(Fixed& f1, Fixed& f2)
{
	
}

Fixed&	Fixed::max(const Fixed& f1, const Fixed& f2)
{
	
}

Fixed&	Fixed::max(Fixed& f1, Fixed& f2)
{
	
}
