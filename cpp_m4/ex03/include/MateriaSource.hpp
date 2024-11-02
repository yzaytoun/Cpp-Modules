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

class MateriaSource : IMateriaSource
{
	private:
		std::string	name;

	public:
		MateriaSource();
		~MateriaSource();
		
		virtual void learnMateria(AMateria*);
		virtual AMateria* createMateria(std::string const & type);
};
