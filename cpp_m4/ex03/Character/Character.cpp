/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 18:24:03 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/11/05 19:46:32 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(std::string const name) : _name(name)
{
	std::cout << "Character constructor called" << std::endl;
}

std::string const & Character::getName() const
{
	return (this->_name);
	std::cout << "Character destructor called" << std::endl;
}

void Character::equip(AMateria* m)
{
	int	idx = 0;

	while (idx < 4)
	{
		if (!this->_inventory[idx])
			this->_inventory[idx] = m;
	}
}

void Character::unequip(int idx)
{
	int	i = 0;

	while (i < 4)
	{
		if (i == idx)
			this->_inventory[idx] = NULL;
		++i;
	}
}

void Character::use(int idx, ICharacter& target)
{
	int	i = 0;

	while (i < 4)
	{
		if (i == idx)
			this->_inventory[idx]->use(target);
		++i;
	}
}
