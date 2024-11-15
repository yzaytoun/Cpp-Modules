/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 16:54:14 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/11/15 18:22:25 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void) : _fixed_point(0)
{
	//print("Default constructor called", 1);
}

Fixed::Fixed(const Fixed& f) : _fixed_point(f.getRawBits())
{
	//print("Copy constructor called", 1);
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
	//print("Destructor called", 1);
}

Fixed&	Fixed::operator=(const Fixed &f)
{
	//print("Copy assignment operator called", 1);
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
	//print("getRawBits member function called", 1);
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

bool	Fixed::operator<(const Fixed& f1) const
{
	return (f1.toFloat() < this->toFloat());
}

bool	Fixed::operator>(const Fixed& f1) const
{
	return (f1.toFloat() > this->toFloat());
}

bool	Fixed::operator<=(const Fixed& f1) const
{
	return (f1.toFloat() <= this->toFloat());
}

bool	Fixed::operator>=(const Fixed& f1) const
{
	return (f1.toFloat() >= this->toFloat());
}

bool	Fixed::operator==(const Fixed& f1) const
{
	return (f1.toFloat() == this->toFloat());
}

bool	Fixed::operator!=(const Fixed& f1) const
{
	return (f1.toFloat() != this->toFloat());
}

Fixed	Fixed::operator+(const Fixed& f1) const
{
	Fixed	res(f1.toFloat() + this->toFloat());
	
	return (res);
}

Fixed	Fixed::operator-(const Fixed& f1) const
{
	Fixed	res(f1.toFloat() - this->toFloat());
	
	return (res);
}

Fixed	Fixed::operator/(const Fixed& f1) const
{
	Fixed	res(f1.toFloat() / this->toFloat());
	
	return (res);
}

Fixed	Fixed::operator*(const Fixed& f1) const
{
	Fixed	res(f1.toFloat() * this->toFloat());

	return (res);
}

const Fixed&	Fixed::operator++()
{
	this->_fixed_point++;
	return (*this);
}

const Fixed&	Fixed::operator--()
{
	this->_fixed_point--;
	return (*this);
}

const Fixed		Fixed::operator++(int i)
{
	(void)i;
	Fixed	before = *this;

	this->_fixed_point++;
	return (before);
}

const Fixed	Fixed::operator--(int i)
{
	(void)i;
	Fixed	before = *this;

	this->_fixed_point--;
	return (before);
}

const Fixed&	Fixed::min(const Fixed& f1, const Fixed& f2)
{
	if (f1._fixed_point < f2._fixed_point)
		return (f1);
	else
		return (f2);
}

const Fixed&	Fixed::min(Fixed& f1, Fixed& f2)
{
	if (f1._fixed_point < f2._fixed_point)
		return (f1);
	else
		return (f2);
}

const Fixed&	Fixed::max(const Fixed& f1, const Fixed& f2)
{
	if (f1._fixed_point > f2._fixed_point)
		return (f1);
	else
		return (f2);
}

const Fixed&	Fixed::max(Fixed& f1, Fixed& f2)
{
	if (f1._fixed_point > f2._fixed_point)
		return (f1);
	else
		return (f2);
}
