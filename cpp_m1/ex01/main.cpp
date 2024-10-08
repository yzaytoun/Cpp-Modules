/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 12:20:53 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/08/13 18:22:47 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	const int	size = 5;
	int			index = 0;
	Zombie		*horde = zombieHorde(size, "Horde!");

	if (horde)
	{
		while (index < size)
		{
			std::cout << "Num:" << index << " -> ";
			horde[index].announce();
			++index;
		}
		
	}
	delete[] (horde);
	return (EXIT_SUCCESS);
}
