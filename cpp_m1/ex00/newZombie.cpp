/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 15:43:42 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/08/13 12:44:22 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <string>

Zombie*	newZombie(std::string name)
{
	if (name.empty())
		return (NULL);
	Zombie	*newzombie = new Zombie(name);
	if (!newzombie)
		return (NULL);
	return (newzombie);
}
