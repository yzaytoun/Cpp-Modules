/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 18:42:25 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/11/23 15:44:36 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
	std::cout << "ScavTrap default Constructor called" << std::endl;
}

ScavTrap::ScavTrap(const std::string name) : ClapTrap(name)
{
	this->_name = name;
	this->_hit_points = 100;
	this->_energy_points = 50;
	this->_attack_damage = 20;
	std::cout << "ScavTrap " << name << " Constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& scav) : ClapTrap(scav)
{
	std::cout << "ScavTrap Copy constructor called" << std::endl;	
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap Destructor called" << std::endl;
}

ScavTrap&	ScavTrap::operator=(const ScavTrap& clap)
{
	std::cout << "ScavTrap assignment called" << std::endl;
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

void	ScavTrap::attack(const std::string& target)
{
	if (this->checkState())
	{
		this->_energy_points -= 1;
		std::cout
		<< "ScavTrap "
		<< this->_name
		<< " attacks "
		<< target
		<< " ,causing "
		<< this->_attack_damage
		<< " points of damage!" << std::endl;
	}
	else
		std::cout << this->_name << " has no energy!!!" << std::endl;
}

void	ScavTrap::guardGate(void)
{
	std::cout << ClapTrap::getName() << " is now in Gate Keeper mode" << std::endl;
}
