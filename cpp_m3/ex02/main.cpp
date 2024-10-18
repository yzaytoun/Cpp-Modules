/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 12:20:53 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/10/18 19:42:44 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FlagTrap.hpp"

int main( void )
{
	FlagTrap	p("player");
	FlagTrap	m("monster");
	FlagTrap	g(p);
	

	std::cout << "----------------------------" << std::endl;
	p.addDamagePower(2);
	m.addDamagePower(1);
	g.addDamagePower(100);
	g.highFivesGuys();
	int	i = 0;
	while (i < 2)
	{
		p.attack(m.getName());
		m.takeDamage(p.getDamage() + i);
		g.attack(m.getName());
		m.takeDamage(g.getDamage() + i);
		m.attack(p.getName());
		p.takeDamage(m.getDamage() + i);
		p.beRepaired(5);
		p.printEnergy();
		g.printEnergy();
		m.printEnergy();
		++i;
	}
	std::cout << "----------------------------" << std::endl;
	return 0;
}
