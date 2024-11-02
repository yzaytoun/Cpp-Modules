/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 13:29:49 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/11/02 15:40:41 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal() : _type("AAnimal"), _brain(NULL)
{
	std::cout << "AAnimal constructor called" << std::endl;
}

AAnimal::~AAnimal()
{
	std::cout << "AAnimal destructor called" << std::endl;
}

AAnimal::AAnimal(const AAnimal& AAnimal) : _type(AAnimal.getType())
{
	std::cout << "AAnimal Copy constructor called" << std::endl;
}

std::string	AAnimal::getType(void) const
{
	return (this->_type);
}

void	AAnimal::makeSound(void) const
{
	std::cout << "AAnimal sound!" << std::endl;
}

void	AAnimal::setIdea(const int idx, const std::string idea)
{
	if (this->_brain)
		this->_brain->setIdea(idx, idea);
}

void	AAnimal::printIdeas(void) const
{
	int	i = 0;

	if (this->_brain)
	{
		while (i < 100)
		{
			if (!this->_brain->getIdea(i).empty())
				std::cout << "AAnimal: index = " << i << " : " << this->_brain->getIdea(i) << std::endl;
			++i;
		}
	}
}
