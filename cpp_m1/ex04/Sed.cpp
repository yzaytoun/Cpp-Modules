/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sed.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 12:49:56 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/09/19 16:25:30 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sed.hpp"

Sed::Sed()
{
}

Sed::~Sed()
{
}

void	Sed::OpenFile(const std::string fname)
{
	if (fname.empty())
		return ;
	this->_fd = std::fopen(fname.c_str(), "r");
}

/*
	Replace str_to_replace inside fullstr with new_str
*/
static void	ReplaceString(std::string fullstr, std::string str_to_replace, std::string new_str)
{
	size_t		pos;
	std::string	sub_str;
	
	size_t	index;

	if (fullstr.empty())
		return ;
	while (pos != std::string::npos && pos <= fullstr.length())
	{
		pos = fullstr.find(str_to_replace);
		if (pos != std::string::npos)
		{
			sub_str = fullstr.substr(pos, str_to_replace.length());
			str_to_replace = new_str;
		}
	}
}

void	Sed::FindAndReplace(std::string str_to_replace, std::string new_str)
{
	std::string	buffer;

	while (this->CheckEoF() == false && len != EOF)
	{
		/*Read file Or getchr*/
		//len = std::fread(&buffer, ,this->_fd);
		FindAndReplace(buffer, str_to_replace, new_str);
	}
}

bool	Sed::IsValidFile(void)
{
	if (!this->_fd)
		return (false);
	return (true);
}

bool	Sed::CheckEoF(void)
{
	bool	ok;

	ok = false;
	if (std::ferror(this->_fd))
	{
		std::cout << "Error in file" << std::endl;
		exit(EXIT_FAILURE);
	}
	else if (std::feof(this->_fd))
	{
		std::cout << "Finished Successfully!" << std::endl;
		std::fclose(this->_fd);
		ok = true;
	}
	return (ok);
}
