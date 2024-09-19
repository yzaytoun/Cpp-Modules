/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 19:07:01 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/09/19 10:53:20 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& weapon) : weapon(weapon)
{
	this->name = name;
}

HumanA::~HumanA()
{
}

void	HumanA::attack( void )
{
	std::cout << "attacks with their " << this->weapon.getType() << std::endl;
}
