/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 19:02:56 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/09/19 10:45:28 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type)
{
	this->type = type;
}

Weapon::~Weapon()
{
}

const std::string	&Weapon::getType( void )
{
	return (this->type);
}

void	Weapon::setType(std::string type)
{
	this->type = type;
}
