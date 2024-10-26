/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 13:34:17 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/10/26 17:40:25 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : _type("Dog"), _brain(new Brain)
{
	std::cout << "Dog constructor called" << std::endl;
}

Dog::~Dog()
{
	delete this->_brain;
	std::cout << "Dog destructor called" << std::endl;
}

void	Dog::makeSound(void) const
{
	std::cout << "Woof!!" << std::endl;
}

std::string	Dog::getType(void) const
{
	return (this->_type);
}

void	Dog::setIdea(const int idx, const std::string idea)
{
	this->_brain->setIdea(idx, idea);
}

void	Dog::printIdeas(void) const
{
	int	i = 0;

	while (i < 100)
	{
		if (!this->_brain->getIdea(i).empty())
			std::cout << "Dog: index = " << i << " : " << this->_brain->getIdea(i) << std::endl;
		++i;
	}
}
