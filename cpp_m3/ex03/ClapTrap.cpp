/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 18:42:25 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/10/26 12:43:47 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(const std::string name) :
	_name(name),
	_hit_points(10),
	_energy_points(10),
	_attack_damage(0)
{
	std::cout << "ClapTrap Constructor called" << std::endl;
}

ClapTrap::ClapTrap(const std::string name, int hit_points, int energy_points, int damage_power) :
	_name(name),
	_hit_points(hit_points),
	_energy_points(energy_points),
	_attack_damage(damage_power)
{
	std::cout << "ClapTrap Constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& clap) : 
	_name(clap.getName()),
	_hit_points(clap._hit_points),
	_energy_points(clap._energy_points),
	_attack_damage(clap._attack_damage)
{
	std::cout << "ClapTrap Copy constructor called" << std::endl;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "ClapTrap Destructor called" << std::endl;
}

ClapTrap&	ClapTrap::operator=(const ClapTrap& clap)
{
	if (this != &clap)
	{
		this->_attack_damage = clap._attack_damage;
		this->_hit_points = clap._hit_points;
		this->_energy_points = clap._energy_points;
		this->_name = clap._name;
	}
	return (*this);
}

std::string		ClapTrap::getName(void) const
{
	return(this->_name);
}

int	ClapTrap::getDamage(void) const
{
	return (this->_attack_damage);
}

void	ClapTrap::printEnergy(void) const
{
	std::cout << this->_name << " has " << this->_energy_points << " energy points" << std::endl;
}

void	ClapTrap::attack(const std::string& target)
{
	if (this->_energy_points > 0)
	{
		this->_energy_points -= 1;
		std::cout
		<< "ClapTrap "
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

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_energy_points > 0)
	{
		this->_hit_points -= amount;
		std::cout << this->_name << " took " << amount << " damage points" << std::endl;
	}
	else
		std::cout << this->_name << " has no energy!!!" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_energy_points > 0)
	{
		this->_energy_points -= 1;
		this->_hit_points += amount;
		std::cout << this->_name << " is recovering with " << amount << " energy" << std::endl;
	}
	else
		std::cout << this->_name << " has no energy!!!" << std::endl;
}

void	ClapTrap::addDamagePower(unsigned int amount)
{
	if (this->_energy_points > 0)
	{
		this->_attack_damage = amount;
		std::cout << this->_name << " acquires " << amount << " power points" << std::endl;
	}
	else
		std::cout << this->_name << " has no energy!!!" << std::endl;
}
