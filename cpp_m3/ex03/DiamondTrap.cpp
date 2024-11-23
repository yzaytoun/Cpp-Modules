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

DiamondTrap::DiamondTrap(const std::string name): ClapTrap(name + "_clap_name")
{
	this->_name = name;
	this->_hit_points = FragTrap::_hit_points;
	this->_energy_points = ScavTrap::_energy_points;
	this->_attack_damage = FragTrap::_attack_damage;
	std::cout << "DiamondTrap " << name << " Constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& clap) : ClapTrap(clap)
{
	this->_name = clap.getName();
	std::cout << "DiamondTrap Copy constructor called" << std::endl;	
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << "DiamondTrap Destructor called" << std::endl;
}

DiamondTrap&	DiamondTrap::operator=(const DiamondTrap& clap)
{
	std::cout << "DiamondTrap assignment called" << std::endl;
	if (this != &clap)
	{
		this->_attack_damage = clap._attack_damage;
		this->_hit_points = clap._hit_points;
		this->_energy_points = clap._energy_points;
		this->_name = clap._name;
	}
	ClapTrap::operator=(clap);
	return (*this);
}

void	DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target);
}

void	DiamondTrap::whoAmI(void) const
{
	std::cout << "DiamondTrap -> " << this->getName() << " | ClapTrap Name -> "<< ClapTrap::getName() << std::endl;
}

std::string	DiamondTrap::getName(void) const
{
	return (this->_name);
}
