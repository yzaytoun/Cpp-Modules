/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 19:01:25 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/06/08 20:22:38 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "PhoneBook.hpp"

STRING	get_input(STRING str)
{
	STRING	input;

	std::cout << str;
	std::getline(std::cin, input);
	return (input);
}

int main(void)
{
	PhoneBook	Book;
	STRING		input;

	while (1)
	{
		input = get_input("Enter Command (ADD/SEARCH/EXIT): ");
		if (input.compare("SEARCH") == 0)
			Book.Search();
		else if (input.compare("ADD") == 0)
			Book.Add();
		else if (input.compare("EXIT") == 0)
			Book.Exit();
	}
	return (0);
}
