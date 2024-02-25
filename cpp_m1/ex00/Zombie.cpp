/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 15:47:54 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/02/25 17:17:02 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/*Default Construct*/
Zombie::Zombie(std::string name)
{
	this->name = name;
	PrintString(name + "Constrcutor called");
}

/*Default Destructor*/
Zombie::~Zombie()
{
	PrintString(this->name + "Destrcutor called");
}

/* Announce Method */
void	Zombie::announce(void)
{
	PrintString(this->name + ": BraiiiiiiinnnzzzZ...");
}

/* Print String to screen */
void	PrintString(std::string argument)
{
	std::cout << argument << std::endl;
}
