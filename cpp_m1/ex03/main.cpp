/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 12:20:53 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/09/07 18:54:47 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

int	main(void)
{
	std::string	str("HI THIS IS BRAIN");
	std::string	*stringPTR = &str;
	std::string	&stringREF = str;

	std::cout << "--- String pointers ---" << std::endl;
	std::cout << "str pointer -> " << &str << std::endl;
	std::cout << "stringPTR pointer -> " << &stringPTR << std::endl;
	std::cout << "stringREF pointer -> " << &stringREF << std::endl;

	std::cout << "--- String values ---" << std::endl;
	std::cout << str << std::endl;
	std::cout << stringPTR << std::endl;
	std::cout << stringREF << std::endl;

	return (0);
}
