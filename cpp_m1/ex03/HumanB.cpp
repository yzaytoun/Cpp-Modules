/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 19:09:19 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/09/07 19:21:43 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
	this->name = name;
}

HumanB::~HumanB()
{
}

void	HumanB::setWeapon(Weapon weapon)
{
	this->weapon = &weapon;	
}

void	HumanB::attack( void )
{
	std::cout << "attacks with their" << weapon->getType() << std::endl;
}