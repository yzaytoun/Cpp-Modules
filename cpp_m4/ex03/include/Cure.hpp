/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 19:29:39 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/11/05 18:54:35 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include "AMateria.hpp"

class Cure : virtual public AMateria
{
	private:
		std::string	_type;
	public:
		Cure();
		Cure(std::string const & type);
		~Cure();
	
	AMateria* clone() const;
	void use(ICharacter& target);
};
