/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 15:43:53 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/02/25 17:15:38 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <optional>

void	randomChump(std::string name)
{
	Zombie	*zombie = newZombie(name);
	if (zombie != nullptr)
		zombie->announce();
	delete zombie;
}