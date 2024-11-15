/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 12:20:53 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/11/15 18:24:59 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

void	print(std::string str, int endl)
{
	if (endl)
		std::cout << str << std::endl;
	else
		std::cout << str;
}

int main( void )
{
	Fixed a(22);
	Fixed s((float)0.1);
	Fixed d((float)0.12);
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << "S==D" << (s == d) << std::endl;
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << (a == a) << std::endl;
	std::cout << (a != a) << std::endl;
	std::cout << (a == b) << std::endl;
	
	std::cout << b << std::endl;
	
	std::cout << Fixed::max( a, b ) << std::endl;
	return 0;
}
