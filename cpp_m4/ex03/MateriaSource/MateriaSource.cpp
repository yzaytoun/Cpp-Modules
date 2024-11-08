/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 18:26:42 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/11/02 20:33:56 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
    int idx = 0;

    while (idx < 4)
    {
        this->_inventory[idx] = NULL;
        ++idx;
    }
    //std::cout << "MateriaSource constructor called" << std::endl;
}

MateriaSource::~MateriaSource()
{
    int idx = 0;

    while (idx < 4)
    {
        delete this->_inventory[idx];
        ++idx;
    }
    //std::cout << "MateriaSource destructor called" << std::endl;
}

void MateriaSource::learnMateria(AMateria* mat)
{
    int idx = 0;

    while (idx < 4)
    {
        if (!this->_inventory[idx])
        {
            this->_inventory[idx] = mat->clone();
            break ;
        }
        ++idx;
    }
    
}
AMateria* MateriaSource::createMateria(std::string const & type)
{
    int idx = 0;

    while (idx < 4)
    {
        if (this->_inventory[idx]->getType() == type)
            return(this->_inventory[idx]->clone());
        ++idx;
    }
	return (NULL);
}
