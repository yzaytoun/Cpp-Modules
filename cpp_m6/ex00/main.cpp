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

int main(void)
{
	char	buffer[BUFSIZ];
	size_t	len = 1;

	while (len > 0)
	{
		len = read(0, buffer, BUFSIZ);
		if (len > 0)
			std::cout << "-----------" << std::endl;
			std::cout << ScalarConverter::convert(buffer) << std::endl;
	}
	
	return (EXIT_SUCCESS);
}
