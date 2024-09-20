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
	this->_ifd.open(fname, std::fstream::in);
	this->_fname = fname;
}

bool	Sed::IsValidFile(void)
{
	return (this->_ifd.is_open());
}

void	Sed::WriteToFile(void)
{
	this->_ofd.open((this->_fname + ".replace"), std::ofstream::out | std::ofstream::app);
	if (this->_ofd.is_open())
	{
		this->_ofd.write(this->_buffer.c_str(), this->_buffer.length());
		this->_ofd.close();
	}
}

void	Sed::CloseFile(void)
{
	this->_ifd.close();
}
