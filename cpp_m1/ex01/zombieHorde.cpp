/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 12:55:55 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/08/13 18:27:36 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie	*zombieHorde(int N, std::string name)
{
	Zombie	*horde;
	int		index = 0;

	if (name.empty() || N < 0)
		return (NULL);
	horde = new Zombie[N];
	while (index < N)
	{
		horde[index].setname(name);
		++index;
	}
	return (horde);
}
