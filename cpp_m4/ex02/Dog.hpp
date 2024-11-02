/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 13:33:30 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/11/02 15:42:42 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AAnimal.hpp"

class Dog : virtual public AAnimal
{
	private:
		std::string	_type;
		Brain		*_brain;
	public:
		Dog();
		~Dog();
	
	std::string	getType(void) const;
	void		makeSound(void) const;
	void		printIdeas(void) const;
	void		setIdea(const int idx, const std::string idea);
};
