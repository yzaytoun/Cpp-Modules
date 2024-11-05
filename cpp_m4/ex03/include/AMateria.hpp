/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 18:19:06 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/11/05 19:50:47 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include "ICharacter.hpp"

class AMateria
{
	protected:
		std::string	_type;
		ICharacter&	target;
	public:
		AMateria();
		AMateria(std::string const & type);
		virtual ~AMateria();
		AMateria(const AMateria & mat);
	
	std::string const & getType() const;
	virtual AMateria* clone() const = 0;
	virtual void use(ICharacter& target);
};
