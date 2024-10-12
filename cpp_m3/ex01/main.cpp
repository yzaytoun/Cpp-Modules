/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 12:20:53 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/10/12 19:41:02 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main( void )
{
	ScavTrap	p("player");
	ScavTrap	m("monster");
	ScavTrap	g(p);
	

	std::cout << "----------------------------" << std::endl;
	p.addDamagePower(2);
	m.addDamagePower(1);
	g.addDamagePower(100);
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
