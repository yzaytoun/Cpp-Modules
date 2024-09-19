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
#include <string>
#include <cstdio>

class Sed
{
private:
	std::string	_fname;
	FILE		*_fd;
	std::string	_s1;
	std::string	_s2;
public:
	Sed();
	~Sed();

	void	OpenFile(std::string fname);
	void	FindAndReplace(std::string str_to_replace, std::string new_str);
	bool	IsValidFile(void);
	bool	CheckEoF(void);
};
