/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 12:20:53 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/11/15 18:35:35 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

void	print(std::string str, int endl)
{
	if (endl)
		std::cout << str << std::endl;
	else
		std::cout << str;
}

int main( void )
{
	Point	p1(5, 5);
	Point	p2(1, 1);
	Point	p3(1, 5);
	Point	p4(3, 3);


	std::cout << bsp(p1, p2, p3, p4) << std::endl;
	Point	pp(-1, -10);
	std::cout << bsp(p1, pp, p3, p4) << std::endl;
	Point	pp1(5, 5);
	std::cout << bsp(p1, pp1, p3, p4) << std::endl;
	Point	pp2(10, 5);
	std::cout << bsp(p1, p2, p3, pp2) << std::endl;
	return 0;
}
