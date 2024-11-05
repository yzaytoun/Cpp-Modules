/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 19:31:58 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/11/05 18:54:51 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice() : _type("ice")
{
	std::cout << "Ice constructor called" << std::endl;
}

Ice::Ice(std::string const & type) : _type(type)
{
	std::cout << "Ice constructor called" << std::endl;
}

Ice::~Ice()
{
	std::cout << "Ice destructor called" << std::endl;
}

AMateria* Ice::clone() const
{
	return (new Ice());
}

void	Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << "*" << std::endl;
}
