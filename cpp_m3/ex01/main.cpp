/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 12:20:53 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/11/23 13:28:53 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

void	print_sep(void)
{
	std::cout << "-------------------------------" << std::endl;
}

int main( void )
{
	ScavTrap	p("player");
	ScavTrap	m("monster");
	ScavTrap	g(p);
	print_sep();
	ScavTrap	a("def");
	a = p;
	print_sep();
	
	p.addDamagePower(2);
	m.addDamagePower(1);
	g.addDamagePower(100);
	g.guardGate();
	print_sep();
	int	i = 0;
	while (i < 2)
	{
		p.attack(m.getName());
		m.takeDamage(p.getDamage() + i);
		print_sep();
		g.attack(m.getName());
		m.takeDamage(g.getDamage() + i);
		print_sep();
		m.attack(p.getName());
		p.takeDamage(m.getDamage() + i);
		print_sep();
		p.beRepaired(5);
		p.printState();
		g.printState();
		m.printState();
		print_sep();
		++i;
	}
	return 0;
}
