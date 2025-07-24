/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
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

template<typename T>
void	swap(T& x, T& y)
{
	T	temp = y;
	y = x;
	x = temp;
}

template<typename T>
T	max(const T& x, const T& y)
{
	if (x > y)
		return (x);
	else
		return (y);
}

template<typename T>
T	min(const T& x, const T& y)
{
	if (x < y)
		return (x);
	else
		return (y);
}
