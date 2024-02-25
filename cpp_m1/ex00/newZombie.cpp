/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 15:43:42 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/02/25 17:10:48 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <string>

Zombie*	newZombie(std::string name)
{
	if (name.empty())
		return (nullptr);
	Zombie	*newzombie = new Zombie(name);
	if (newzombie == nullptr)
		return (nullptr);
	return (newzombie);
}
