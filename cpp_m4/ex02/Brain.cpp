/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 15:57:04 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/10/26 17:39:13 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain constructor called" << std::endl;
}

Brain::~Brain()
{
	std::cout << "Brain destructor called" << std::endl;
}

Brain::Brain(const Brain& brain)
{
	int	i = 0;

	if (this != &brain)
	{
		while (i < 100)
		{
			this->ideas[i] = brain.ideas[i];
			++i;
		}
	}
	std::cout << "Brain copy constructor called" << std::endl;
}

std::string	Brain::getIdea(int idx)
{
	if (idx >= 0 && idx < 100)
		return (this->ideas[idx]);
	return (NULL);
}

void	Brain::setIdea(const int idx, const std::string idea)
{
	if (idx >= 0 && idx < 100)
		this->ideas[idx] = idea;
}
