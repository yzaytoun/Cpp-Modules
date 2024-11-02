/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 13:26:26 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/11/02 15:42:38 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AAnimal.hpp"

class Cat : virtual public AAnimal
{
	private:
		std::string	_type;
		Brain		*_brain;
	public:
		Cat();
		~Cat();
	
	std::string	getType(void) const;
	void		makeSound(void) const;
	void		printIdeas(void) const;
	void		setIdea(const int idx, const std::string idea);
};
