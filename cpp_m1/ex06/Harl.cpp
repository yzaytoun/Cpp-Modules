/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 17:25:30 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/09/20 20:09:58 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl()
{
}

Harl::~Harl()
{
}

void	Harl::_debug( void )
{
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout <<
		"I love having extra bacon for my"
		" 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void	Harl::_info( void )
{
	std::cout << "[ INFO ]" << std::endl;	
	std::cout <<
		"I cannot believe adding extra bacon costs more money. You didn't put"
		" enough bacon in my burger! If you did, I wouldn't be asking for more!" << std::endl;	
}

void	Harl::_warning( void )
{
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free. I've been coming for"
		" years whereas you started working here since last month" << std::endl;
}

void	Harl::_error( void )
{
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now" << std::endl;
}

void	Harl::_default( void )
{
	std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
}

void	Harl::complain(std::string level)
{
	std::string	func_names[5] = {"debug", "info", "warning", "error", "default"};
	void		(Harl::*func[5])(void) = {
		&Harl::_debug,
		&Harl::_info,
		&Harl::_warning,
		&Harl::_error,
		&Harl::_default
	};
	int	i = -1;

	while (++i < 4 && func_names[i].compare(level))
		;
	if (i <= 4)
		(this->*func[i])();
}
