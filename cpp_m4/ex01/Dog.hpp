/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 13:33:30 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/10/26 17:26:11 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"

class Dog : virtual public Animal
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
