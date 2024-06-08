/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 18:55:25 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/06/08 21:49:31 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	this->currcount = 0;
	std::cout << "PhoneBook Constructor Called" << std::endl;
}

PhoneBook::~PhoneBook()
{
	std::cout << "PhoneBook Destructor Called" << std::endl;
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
	input.assign(get_input("Insert Phone Number: "));
	this->Contacts[currcount].Set(input, PHONE);
	input.assign(get_input("Insert Secret: "));
	this->Contacts[currcount].Set(input, SECRET);
}

int	PhoneBook::CurrentSize(void)
{
	int	count = 0;

	while (!this->Contacts[count].Get(FIRST_NAME).empty())
		count++;
	return (count);
}

/// Add Truncate string

static void	DisplayContacts(Contact contacts[8], int size)
{
	int	index;

	std::cout << "Index\tFirst Name\t|\tLast Name\t|\tnickname\n" << std::endl;
	while (index < size)
	{
		std::cout
			<< "["
			<< index
			<< "]"
			<< "\t|\t"
			<< contacts[index].Get(FIRST_NAME)
			<< "|\t"
			<< contacts[index].Get(LAST_NAME)
			<< "|\t"
			<< contacts[index].Get(NICKNAME)
			<< std::endl;
		++index;
	}
}

static bool	IsValidNum(const STRING str)
{
	int	x = 0;

	while (str.at(x) != '\0')
	{
		if (isdigit(str.at(x)) == false)
			return (false);
		++x;
	}
	return (true);
}

Contact	PhoneBook::Search(void)
{
	STRING	input;
	int		index;
	Contact	contact;

	DisplayContacts(this->Contacts, this->CurrentSize());
	input = get_input("Insert Index: ");
	if (IsValidNum(input) == true)
	{
		index = std::stoi(input);
		if (index > 7)
		{
			std::cout << "Index out of bound" << std::endl;
			return ;
		}
		contact = this->Contacts[index];
	}
	return (contact);
}

void	PhoneBook::Exit(void)
{
	std::cout << "Exiting... " << std::endl;
	exit(0);
}