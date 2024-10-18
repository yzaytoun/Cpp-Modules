/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FlagTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 18:42:25 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/10/18 19:42:14 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FlagTrap.hpp"

FlagTrap::FlagTrap(const std::string name) : ClapTrap(name, 100, 100, 30)
{
	std::cout << "FlagTrap Constructor called" << std::endl;
}

FlagTrap::FlagTrap(const FlagTrap& flag) : ClapTrap(flag)
{
	std::cout << "FlagTrap Copy constructor called" << std::endl;	
}

FlagTrap::~FlagTrap(void)
{
	std::cout << "FlagTrap Destructor called" << std::endl;
}

void	FlagTrap::attack(const std::string& target)
{
	ClapTrap::attack(target);
}

void	FlagTrap::highFivesGuys(void)
{
	std::cout << "HIGH FIVE !!!!" << std::endl;
}
