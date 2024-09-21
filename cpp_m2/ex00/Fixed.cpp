/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 16:54:14 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/09/21 18:59:13 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void)
{
	this->_fixed_point = 0;
}

Fixed::Fixed(const Fixed& f) : _fixed_point(f.getRawBits())
{
	std::cout << "Copy Fixed object" << std::endl;
}

Fixed::~Fixed()
{
}

Fixed&	Fixed::operator = (const Fixed &f)
{
	if (this != &f)
		this->_fixed_point = f.getRawBits();
	return (*this);
}

int	Fixed::getRawBits(void) const
{
	return (this->_fixed_point);
}

void	Fixed::setRawBits(int const raw)
{
	this->_fixed_point = raw;
}
