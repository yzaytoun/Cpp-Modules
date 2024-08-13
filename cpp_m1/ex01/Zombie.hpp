/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 15:43:15 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/08/13 18:25:56 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <string>
#include <iostream>
#include <cstdlib>
#include <new>

class Zombie
{
	private:
		std::string	name;
	
	public:
		Zombie();
		Zombie(std::string);
		~Zombie();
		void	announce(void);
		void	setname(std::string name);
};

void	PrintString(std::string argument);
Zombie* zombieHorde(int N, std::string name);

#endif