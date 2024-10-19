/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 18:42:25 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/10/19 19:41:26 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(const std::string name) : ClapTrap(name, 100, 100, 30)
{
	std::cout << "FragTrap Constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap& flag) : ClapTrap(flag)
{
	std::cout << "FragTrap Copy constructor called" << std::endl;	
}

FragTrap::~FragTrap(void)
{
	std::cout << "FragTrap Destructor called" << std::endl;
}

void	FragTrap::attack(const std::string& target)
{
	ClapTrap::attack(target);
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << "HIGH FIVE !!!!" << std::endl;
}
