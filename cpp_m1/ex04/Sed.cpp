/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sed.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 12:49:56 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/09/20 17:17:49 by yzaytoun         ###   ########.fr       */
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
	this->_ifd.open(fname.c_str(), std::fstream::in);
}

bool	Sed::IsValidFile(void)
{
	return (this->_ifd.is_open());
}

void	Sed::WriteToFile(std::string fname)
{
	std::string	filename = fname + ".replace";

	this->_ofd.open(filename.c_str(), std::ofstream::out | std::ofstream::app);
	if (this->_ofd.is_open())
		this->_ofd.write(this->_buffer.c_str(), this->_buffer.length());
}

void	Sed::CloseFile(void)
{
	this->_ifd.close();
	this->_ofd.close();
}
