/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 19:32:20 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/11/05 18:58:40 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include "AMateria.hpp"

class Ice : virtual public AMateria
{
	private:
		std::string	_type;
	public:
		Ice();
		Ice(std::string const & type);
		~Ice();
	
	virtual AMateria* clone() const;
	virtual void use(ICharacter& target);
};
