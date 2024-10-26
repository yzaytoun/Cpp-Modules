/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 15:48:16 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/10/26 15:48:47 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "WrongAnimal.hpp"

class WrongCat : virtual public WrongAnimal
{
	private:
		std::string	_type;
	public:
		WrongCat();
		~WrongCat();
	
	std::string	getType(void) const;
	void		makeSound(void) const;
};
