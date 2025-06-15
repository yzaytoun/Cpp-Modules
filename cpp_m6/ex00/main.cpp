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

#include "ScalarConverter.hpp"
#include <unistd.h>

int main(int ac, char **av)
{
	(void)ac;
	(void)av;
	//if (ac == 2)
	//{
	//	std::cout << ScalarConverter::convert(av[1]) << std::endl;
	//}
	//else
	//{
	//	std::cerr << "Only two arguments are allowed!" << std::endl;
	//	return (EXIT_FAILURE);
	//}
	char	buffer[BUFSIZ];
	size_t	len;

	while (true)
	{
		len = read(0, buffer, BUFSIZ);
		if (len > 0)
			std::cout << ScalarConverter::convert(buffer) << std::endl;
	}
	
	return (EXIT_SUCCESS);
}
