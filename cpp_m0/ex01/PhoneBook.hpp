/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 17:54:40 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/06/16 16:21:56 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
# define PHONEBOOK_H

# include "Contact.hpp"
# include <iostream>
# include <string>
# include <cstdlib>
# include <iomanip>

# define CONTACT_MAX 8
# define MAIN 1

class PhoneBook
{
private:
	Contact		Contacts[CONTACT_MAX];
	int			CurrentSize();
	int			currcount;
public:
	PhoneBook();
	~PhoneBook();
 
	void		Add(void);
	void		Exit(void);
	void		Search(void);
};

STRING	get_input(STRING str, int key);
bool	IsValidNum(const STRING str);

#endif