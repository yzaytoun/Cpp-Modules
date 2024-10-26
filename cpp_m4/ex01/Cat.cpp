/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 13:26:03 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/10/26 17:40:31 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : _type("Cat"), _brain(new Brain)
{
	std::cout << "Cat constructor called" << std::endl;
}

Cat::~Cat()
{
	delete this->_brain;
	std::cout << "Cat destructor called" << std::endl;
}

void	Cat::makeSound(void) const
{
	std::cout << "miaow!!" << std::endl;
}

std::string	Cat::getType(void) const
{
	return (this->_type);
}

void	Cat::setIdea(const int idx, const std::string idea)
{
	this->_brain->setIdea(idx, idea);
}

void	Cat::printIdeas(void) const
{
	int	i = 0;

	while (i < 100)
	{
		if (!this->_brain->getIdea(i).empty())
			std::cout << "Cat: index = " << i << " : " << this->_brain->getIdea(i) << std::endl;
		++i;
	}
}
