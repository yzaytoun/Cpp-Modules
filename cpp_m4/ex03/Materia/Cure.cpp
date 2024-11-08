/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 19:29:00 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/11/05 18:54:32 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure() : AMateria("cure"), _type("cure")
{
	//std::cout << "Cure constructor called" << std::endl;
}

Cure::Cure(std::string const & type) : AMateria(type), _type(type)
{
	//std::cout << "Cure constructor called" << std::endl;
}

Cure::~Cure()
{
	//std::cout << "Cure destructor called" << std::endl;
}

AMateria* Cure::clone() const
{
	return (new Cure());
}

void	Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
