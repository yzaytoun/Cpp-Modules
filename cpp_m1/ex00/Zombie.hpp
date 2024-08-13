/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 15:43:15 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/08/13 12:52:03 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <string>
#include <iostream>
#include <cstdlib>

class Zombie
{
	private:
		std::string	name;
	
	public:
		Zombie(std::string);
		~Zombie();
		void	announce(void);
};

void	PrintString(std::string argument);
Zombie	*newZombie(std::string name);
void	randomChump(std::string name);

#endif