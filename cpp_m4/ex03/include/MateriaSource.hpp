/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 18:26:59 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/11/02 20:33:11 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include "IMateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

class MateriaSource : public IMateriaSource
{
	private:
		AMateria	*_inventory[4];

	public:
		MateriaSource();
		~MateriaSource();

	void learnMateria(AMateria* mat);
	AMateria* createMateria(std::string const & type);
};
