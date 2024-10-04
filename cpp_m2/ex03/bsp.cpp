/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 18:51:09 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/10/04 18:35:33 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	const float	denominator = (
		(b.getY().toFloat() - c.getY().toFloat())
		* (a.getX().toFloat() - c.getX().toFloat())
		+ (c.getX().toFloat() - b.getX().toFloat())
		* (a.getY().toFloat() - c.getY().toFloat()));
	const float	w1 = (
		(b.getY().toFloat() - c.getY().toFloat())
		* (point.getX().toFloat() - c.getX().toFloat())
		+ (c.getX().toFloat() - b.getX().toFloat())
		* (point.getY().toFloat() - c.getY().toFloat())
	) / denominator;
	const float	w2 = (
		(c.getY().toFloat() - a.getY().toFloat())
		* (point.getX().toFloat() - c.getX().toFloat())
		+ (a.getX().toFloat() - c.getX().toFloat())
		* (point.getY().toFloat() - c.getY().toFloat())
	) / denominator;
	const float	w3 = 1 - w1 - w2;

	if (denominator != 0 && w1 >= 0 && w2 >= 0 && w3 >= 0)
		return (true);
	return (false);
}
