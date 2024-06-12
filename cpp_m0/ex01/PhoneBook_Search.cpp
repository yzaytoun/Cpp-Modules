/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook_Search.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 20:24:42 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/06/11 20:51:21 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	PhoneBook::CurrentSize(void)
{
	int	count = 0;

	while (!this->Contacts[count].Get(FIRST_NAME).empty() && count < 8)
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

	std::cout
		<< "\nIndex | First Name | Last Name | nickname\n"
		<< "-------------------------------------------------" << std::endl;
	while (index < size)
	{
		std::cout
			<< "["
			<< index
			<< "]"
			<< " | "
			<< TruncateString(contacts[index].Get(FIRST_NAME))
			<< " | "
			<< TruncateString(contacts[index].Get(LAST_NAME))
			<< " | "
			<< TruncateString(contacts[index].Get(NICKNAME))
			<< std::endl;
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
	input = get_input("Insert Index: ");
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
