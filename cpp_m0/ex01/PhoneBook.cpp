/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 18:55:25 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/06/11 20:46:33 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	this->currcount = -1;
	//std::cout << "PhoneBook Constructor Called" << std::endl;
}

PhoneBook::~PhoneBook()
{
	//std::cout << "PhoneBook Destructor Called" << std::endl;
}

void	PhoneBook::Add(void)
{
	STRING	input;

	this->currcount += 1;
	if (this->currcount > 7) /*Return to first entry*/
		this->currcount = 0;
	input = get_input("Insert First Name: ");
	this->Contacts[currcount].Set(input, FIRST_NAME);
	input.assign(get_input("Insert Last Name: "));
	this->Contacts[currcount].Set(input, LAST_NAME);
	input.assign(get_input("Insert Nickname: "));
	this->Contacts[currcount].Set(input, NICKNAME);
	while (IsValidNum(input) == false)
	{
		input.assign(get_input("Insert Phone Number: "));
		if (IsValidNum(input) == true)
			this->Contacts[currcount].Set(input, PHONE);
		else
			std::cout << "Not a valid Phone number" << std::endl;
	}
	input.assign(get_input("Insert Secret: "));
	this->Contacts[currcount].Set(input, SECRET);
}

void	PhoneBook::Exit(void)
{
	std::cout << "Exiting... " << std::endl;
	exit(0);
}