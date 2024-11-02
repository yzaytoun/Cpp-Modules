/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 13:31:01 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/11/02 15:43:27 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include "Brain.hpp"

class AAnimal
{
	protected:
		std::string	_type;
		Brain		*_brain;

	public:
		AAnimal();
		virtual ~AAnimal();
		AAnimal(const AAnimal& AAnimal);
	
	virtual std::string		getType(void) const = 0;
	virtual void			makeSound(void) const = 0;
	virtual void			printIdeas(void) const = 0;
	virtual void			setIdea(const int idx, const std::string idea) = 0;
};
