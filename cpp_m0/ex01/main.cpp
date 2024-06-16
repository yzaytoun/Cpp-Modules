/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 19:01:25 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/06/16 16:22:12 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "PhoneBook.hpp"

STRING	get_input(STRING str, int key)
{
	STRING	input;

	while (input.empty() && std::cin.good())
	{
		std::cout << str;
		std::getline(std::cin, input);
		if (input.empty() && key != MAIN)
			std::cout << "**** Empty fields are not allowed ****" << std::endl;
	}
	return (input);
}

int main(void)
{
	PhoneBook	Book;
	STRING		input;

	while (std::cin.good())
	{
		input = get_input("Enter Command (ADD/SEARCH/EXIT): ", MAIN);
		if (input.compare("SEARCH") == 0)
			Book.Search();
		else if (input.compare("ADD") == 0)
			Book.Add();
		else if (input.compare("EXIT") == 0)
			Book.Exit();
	}
	return (0);
}
