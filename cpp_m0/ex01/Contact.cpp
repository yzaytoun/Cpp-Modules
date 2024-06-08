/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 19:04:42 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/06/08 21:14:05 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact()
{
	std::cout << "Contact Constructor Called" << std::endl;
}

Contact::~Contact()
{
	std::cout << "Contact Destructor Called" << std::endl;
}

void	Contact::Set(const STRING str, t_key key)
{
	if (str.empty())
		return ;
	if (key == FIRST_NAME)
		this->first_name = str;
	else if (key == LAST_NAME)
		this->last_name = str;
	else if (key == NICKNAME)
		this->nickname = str;
	else if (key == PHONE)
		this->phone = str;
	else if (key == SECRET)
		this->secret = str;
}

STRING	Contact::Get(t_key key)
{
	STRING	output;

	if (key == FIRST_NAME)
		output = this->first_name;
	else if (key == LAST_NAME)
		output = this->last_name;
	else if (key == NICKNAME)
		output = this->nickname;
	else if (key == PHONE)
		output = this->phone;
	else if (key == SECRET)
		output = this->secret;
	return (output);
}