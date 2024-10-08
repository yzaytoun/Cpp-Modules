/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 15:43:15 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/09/07 17:13:25 by yzaytoun         ###   ########.fr       */
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
		~Zombie();
		Zombie(std::string);
		void	announce(void);
		void	setname(std::string name);
};

void	PrintString(std::string argument);
Zombie* zombieHorde(int N, std::string name);

#endif