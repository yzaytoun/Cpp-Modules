/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 15:43:15 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/08/13 14:20:48 by yzaytoun         ###   ########.fr       */
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
		Zombie(std::string);
		~Zombie();
		void	announce(void);
		void	*operator new(size_t size);
		void	operator delete(void *ptr);
};

void	PrintString(std::string argument);
Zombie* zombieHorde(int N, std::string name);

#endif