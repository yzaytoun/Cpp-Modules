/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 18:42:25 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/11/23 15:44:51 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap()
{
	std::cout << "FragTrap default Constructor called" << std::endl;
}

FragTrap::FragTrap(const std::string name) : ClapTrap(name)
{
	this->_name = name;
	this->_hit_points = 100;
	this->_energy_points = 100;
	this->_attack_damage = 30;
	std::cout << "FragTrap " << name << " Constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap& flag) : ClapTrap(flag)
{
	std::cout << "FragTrap Copy constructor called" << std::endl;	
}

FragTrap::~FragTrap(void)
{
	std::cout << "FragTrap Destructor called" << std::endl;
}

FragTrap&	FragTrap::operator=(const FragTrap& clap)
{
	std::cout << "FragTrap assignment called" << std::endl;
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

void	FragTrap::attack(const std::string& target)
{
	if (this->checkState())
	{
		this->_energy_points -= 1;
		std::cout
		<< "FragTrap "
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

void	FragTrap::highFivesGuys(void)
{
	std::cout << "HIGH FIVE !!!!" << std::endl;
}
