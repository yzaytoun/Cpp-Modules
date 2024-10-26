/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 13:31:01 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/10/26 17:27:25 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include "Brain.hpp"

class Animal
{
	protected:
		std::string	_type;
		Brain		*_brain;

	public:
		Animal();
		virtual ~Animal();
		Animal(const Animal& animal);
	
	virtual std::string		getType(void) const;
	virtual void			makeSound(void) const;
	virtual void			printIdeas(void) const;
	virtual void			setIdea(const int idx, const std::string idea);
};
