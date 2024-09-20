/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sed.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 12:49:23 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/09/19 16:09:49 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <fstream>
#include <string>

class Sed
{
private:
	std::string		_fname;
	std::ifstream	_ifd;
	std::ofstream	_ofd;
	std::string		_buffer;
public:
	Sed();
	~Sed();

	void	OpenFile(std::string fname);
	void	CloseFile(void);
	void	WriteToFile(void);
	void	FindAndReplace(std::string str_to_replace, std::string new_str);
	bool	IsValidFile(void);
};
