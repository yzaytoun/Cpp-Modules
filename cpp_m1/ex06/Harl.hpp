/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 17:24:57 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/09/20 20:27:07 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <cctype>
#include <stdio.h>

typedef enum e_message
{
	DEBUG,
	INFO,
	WARNING,
	ERROR,
	DEFAULT
}t_msg;

class Harl
{
	private:
		void	_debug( void );
		void	_info( void );
		void	_warning( void );
		void	_error( void );
		void	_default( void );
	public:
		Harl();
		~Harl();
		
		void	complain(std::string level);
};

