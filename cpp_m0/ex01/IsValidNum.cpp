/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IsValidNum.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 20:25:40 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/06/11 20:26:55 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

bool	IsValidNum(const STRING str)
{
	int	x = 0;
	int	len = (int)str.length();

	while (x < len)
	{
		if (isdigit(str.at(x)) == false)
			return (false);
		++x;
	}
	return (true);
}
