/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 12:20:53 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/10/26 17:51:13 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"

int main( void )
{
	Animal*	animal_array[10] = {
		new Dog(),
		new Cat(),
		new Dog(),
		new Cat(),
		new Dog(),
		new Cat(),
		new Dog(),
		new Cat(),
		new Dog(),
		new Cat(),
		};
	int	i = 0;
	int	index = -1;

	while (++index < 10)
	{
		i = 0;
		while (i < 5)
		{
			animal_array[index]->setIdea(i, "idea");
			++i;
		}
	}
	
	index = -1;
	while (++index < 10)
	{
		animal_array[index]->printIdeas();
		std::cout << "-----------------------------" << std::endl;
	}
	
	index = -1;
	while (++index < 10)
		delete animal_array[index];
	return 0;
}
