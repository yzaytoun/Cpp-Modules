/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 13:29:49 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/10/26 17:40:14 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : _type("Animal"), _brain(NULL)
{
	std::cout << "Animal constructor called" << std::endl;
}

Animal::~Animal()
{
	std::cout << "Animal destructor called" << std::endl;
}

Animal::Animal(const Animal& animal) : _type(animal.getType())
{
	std::cout << "Animal Copy constructor called" << std::endl;
}

std::string	Animal::getType(void) const
{
	return (this->_type);
}

void	Animal::makeSound(void) const
{
	std::cout << "Animal sound!" << std::endl;
}

void	Animal::setIdea(const int idx, const std::string idea)
{
	if (this->_brain)
		this->_brain->setIdea(idx, idea);
}

void	Animal::printIdeas(void) const
{
	int	i = 0;

	if (this->_brain)
	{
		while (i < 100)
		{
			if (!this->_brain->getIdea(i).empty())
				std::cout << "Animal: index = " << i << " : " << this->_brain->getIdea(i) << std::endl;
			++i;
		}
	}
}
