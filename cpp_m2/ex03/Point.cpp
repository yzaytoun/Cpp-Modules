/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 18:20:03 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/10/04 18:31:54 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(void) : _x(0), _y(0)
{
}

Point::~Point(void)
{
}

Point::Point(const float x, const float y) : _x(x), _y(y)
{
}

Point::Point(const Point& p) : _x(p._x), _y(p._y)
{
}

bool	operator==(const Point& p1, const Point p2)
{
	if (p1._x == p2._x && p1._y == p2._y)
		return (true);
	return (false);
}

bool	operator!=(const Point& p1, const Point p2)
{
	if (p1._x == p2._x && p1._y == p2._y)
		return (false);
	return (true);	
}

Point&	Point::operator=(const Point& p)
{
	if (this != &p)
		*this = Point(p);
	return (*this);
}

std::ostream&	operator<<(std::ostream& out, const Point& p)
{
	out << "{ " << p._x << " , " << p._y << " }";
	return (out);
}

bool	operator<=(const Point& p1, const Point p2)
{
	if (p1._x <= p2._x && p1._y <= p2._y)
		return (true);
	return (false);	
}

bool	operator>=(const Point& p1, const Point p2)
{
	if (p1._x >= p2._x && p1._y >= p2._y)
		return (true);
	return (false);	
}

bool	operator<(const Point& p1, const Point p2)
{
	if (p1._x < p2._x && p1._y < p2._y)
		return (true);
	return (false);	
}

bool	operator>(const Point& p1, const Point p2)
{
	if (p1._x > p2._x && p1._y > p2._y)
		return (true);
	return (false);	
}

Fixed	Point::getX(void) const
{
	return (this->_x);
}

Fixed	Point::getY(void) const
{
	return (this->_y);
}
