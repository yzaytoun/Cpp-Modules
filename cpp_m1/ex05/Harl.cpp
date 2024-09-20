/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 17:25:30 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/09/20 18:00:55 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl()
{
}

Harl::~Harl()
{
}

void	Harl::debug( void )
{
	std::cout <<
		"DEBUG: love having extra bacon for my\
		7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void	Harl::info( void )
{
	std::cout <<
		"INFO:  cannot believe adding extra bacon costs more money. You didn't put\
		enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;	
}

void	Harl::warning( void )
{
	std::cout <<
		"WARNING: l think I deserve to have some extra bacon for free. I've been coming for\
		years whereas you started working here since last month" << std::endl;
}

void	Harl::error( void )
{
	std::cout <<
		"ERROR: his is unacceptable! I want to speak to the manager now" << std::endl;
}

void	Harl::complain(std::string level)
{
	std::string	func_names[4] = {"debug", "info", "warning", "error"};
	void		(Harl::*func[4])(void) = {
		&Harl::debug,
		&Harl::info,
		&Harl::warning,
		&Harl::error
	};

	int		val = func_names.;
	func[val];
}
