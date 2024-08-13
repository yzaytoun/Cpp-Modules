/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 15:47:54 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/08/13 14:25:24 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/*Default Construct*/
Zombie::Zombie(std::string name)
{
	this->name = name;
	PrintString(name + " Constrcutor called");
}

/*Default Destructor*/
Zombie::~Zombie()
{
	PrintString(this->name + " Destrcutor called");
}

/* Announce Method */
void	Zombie::announce(void)
{
	PrintString(this->name + " : BraiiiiiiinnnzzzZ...");
}

/* Print String to screen */
void	PrintString(std::string argument)
{
	std::cout << argument << std::endl;
}

/*New Constructor*/
void	*operator new(size_t size)
{
	void	*ptr;

	if (size < 0)
		return (NULL);
	ptr = ::operator new(size);
	PrintString("New Constrcutor called");
}

/*Delete Destructor*/
void	operator delete(void *ptr)
{
	PrintString("Delete Destrcutor called");
	free(ptr);
}
