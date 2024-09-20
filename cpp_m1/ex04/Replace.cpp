/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replace.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 12:49:56 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/09/20 17:06:59 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sed.hpp"

/*
	Replace str_to_replace inside fullstr with new_str
*/
static void	ReplaceString(std::string& fullstr, std::string str_to_replace, std::string new_str)
{
	size_t	pos = 0;

	if (fullstr.empty())
		return ;
	while (pos != std::string::npos && pos <= fullstr.length())
	{
		pos = fullstr.find(str_to_replace);
		if (pos != std::string::npos)
		{
			fullstr.erase(pos, str_to_replace.length());
			fullstr.insert(pos, new_str);
		}
	}
}

void	Sed::FindAndReplace(std::string str_to_replace, std::string new_str)
{
	std::stringstream	stream;
	std::string			str("");
	char				c_buff[BUFSIZ] = "";

	while (!this->_ifd.eof() && this->_ifd.good())
	{
		this->_ifd.read(c_buff, BUFSIZ);
		str.assign(c_buff);
		ReplaceString(str, str_to_replace, new_str);
		this->_buffer.append(str);
	}
}
