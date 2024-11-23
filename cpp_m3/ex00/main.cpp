/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 12:20:53 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/11/23 12:54:24 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

void	print_sep(void)
{
	std::cout << "-------------------------------" << std::endl;
}

int main( void )
{
	ClapTrap	p("player");
	ClapTrap	m("monster");

	p.addDamagePower(2);
	m.addDamagePower(1);
	int	i = 0;
	while (i < 2)
	{
		print_sep();
		p.attack(m.getName());
		m.takeDamage(p.getDamage() + i);
		print_sep();
		m.attack(p.getName());
		p.takeDamage(m.getDamage() + i);
		print_sep();
		p.beRepaired(5);
		p.printState();
		m.printState();
		++i;
	}
	return 0;
}
