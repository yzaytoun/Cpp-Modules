/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 12:20:53 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/10/26 15:52:42 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

int main(void)
{
	srand(time(0));
	Base*	g = generate();
	Base*	x = generate();
	Base*	y = generate();
	
	std::cout << "------- Identify by pointer -------" << std::endl;
	std::cout << "g -> ";
	identify(g);
	std::cout << "x -> ";
	identify(x);
	std::cout << "y -> ";
	identify(y);
	
	std::cout << "------- Identify by reference -------" << std::endl;
	std::cout << "g -> ";
	identify(*g);
	std::cout << "x -> ";
	identify(*x);
	std::cout << "y -> ";
	identify(*y);

	delete g;
	delete x;
	delete y;
	return (EXIT_SUCCESS);
}