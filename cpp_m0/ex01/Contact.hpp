/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 19:04:54 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/06/08 21:14:11 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_H
# define CONTACT_H

# include <iostream>

typedef typename std::string STRING;

typedef enum e_key
{
	FIRST_NAME,
	LAST_NAME,
	NICKNAME,
	PHONE,
	SECRET
}	t_key;

class Contact
{
private:
	STRING	first_name;
	STRING	last_name;
	STRING 	nickname;
	STRING	phone;
	STRING	secret;	

public:
	Contact();
	~Contact();

	/* Methods */
	void	Set(STRING str, t_key key);
	STRING	Get(t_key key);
};

#endif