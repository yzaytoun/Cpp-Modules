/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 18:42:25 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/10/12 19:58:58 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(const std::string name): ScavTrap(name + "clap_name"), FragTrap(name)
{
	this->_name = name;
	this->_hit_points = FragTrap::_hit_points;
	std::cout << "DiamondTrap Constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& scav) : ScavTrap(scav), FragTrap(scav)
{
	std::cout << "DiamondTrap Copy constructor called" << std::endl;	
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << "DiamondTrap Destructor called" << std::endl;
}

void	DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target);
}

void	DiamondTrap::whoAmI(void)
{
	std::cout << this->_name << ScavTrap::getName() << " is now the Gate Keeper" << std::endl;
}
