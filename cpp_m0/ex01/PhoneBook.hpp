/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 17:54:40 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/06/13 20:14:11 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
# define PHONEBOOK_H

# include "Contact.hpp"
# include <iostream>
# include <string>
# include <cstdlib>

# define CONTACT_MAX 8

class PhoneBook
{
private:
	Contact		Contacts[8];
	int			CurrentSize();
	int			currcount;
public:
	PhoneBook();
	~PhoneBook();
 
	void		Add(void);
	void		Exit(void);
	void		Search(void);
};

STRING	get_input(STRING str);
int		StringToInteger(std::string str);
bool	IsValidNum(const STRING str);
#endif