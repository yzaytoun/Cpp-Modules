/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook_Search.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 20:24:42 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/06/16 16:25:23 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	PhoneBook::CurrentSize(void)
{
	int	count = 0;

	while (count <= CONTACT_MAX - 1 && !this->Contacts[count].Get(FIRST_NAME).empty())
		count++;
	return (count);
}

static STRING	TruncateString(STRING str)
{
	STRING	truncated;

	if (!str.empty())
	{
		truncated = str;
		if (truncated.length() > 10)
		{
			truncated.resize(10);
			truncated.append(".");
		}
	}
	return (truncated);
}

static void	DisplayContacts(Contact contacts[8], int size)
{
	int	index = 0;
	
	std::cout << "-------------------------------------------------" << std::endl;
	std::cout << std::left << std::setw(10) << "Index" << "|";
	std::cout << std::left << std::setw(10) << "FirstName" << "|";
	std::cout << std::left << std::setw(10) << "LastName" << "|";
	std::cout << std::left << std::setw(10) << "NickName" << std::endl;
	std::cout << "-------------------------------------------------" << std::endl;
	while (index < size)
	{
		std::cout << "[" << index << "]";
		std::cout << std::right << std::setw(8) << "|";
		std::cout << std::left << std::setw(10) << TruncateString(contacts[index].Get(FIRST_NAME)) << "|";
		std::cout << std::left << std::setw(10) << TruncateString(contacts[index].Get(LAST_NAME)) << "|";
		std::cout << std::left << std::setw(10) << TruncateString(contacts[index].Get(NICKNAME));
		std::cout << std::endl;
		++index;
	}
	std::cout << "\n-------------------------------------------------\n" << std::endl;
}

void	PhoneBook::Search(void)
{
	STRING	input;
	int		index;
	int		size = this->CurrentSize();

	if (size > 0)
		DisplayContacts(this->Contacts, size);
	else
	{
		std::cout << "No enteries found, book is empty" << std::endl;
		return ;
	}
	input = get_input("Insert Index: ", 0);
	if (IsValidNum(input) == true)
	{
		index = std::atoi(input.c_str());
		if (index > 7 || index > size - 1 || index < 0)
		{
			std::cout << "Index out of bound" << std::endl;
			return ;
		}
		this->Contacts[index].Print();
	}
	else
		std::cout << "Invalid input" << std::endl;
}
