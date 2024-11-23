/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 12:20:53 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/11/23 13:44:42 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

void	sep(void)
{
	std::cout << "-------------------------------" << std::endl;
}

int main( void )
{
	FragTrap	p("player");
	ScavTrap	m("monster");
	FragTrap	g(p);
	

	p.addDamagePower(2);
	m.addDamagePower(1);
	g.addDamagePower(100);
	g.highFivesGuys();
	sep();
	int	i = 0;
	while (i < 2)
	{
		p.attack(m.getName());
		m.takeDamage(p.getDamage() + i);
		g.attack(m.getName());
		sep();
		m.takeDamage(g.getDamage() + i);
		m.attack(p.getName());
		p.takeDamage(m.getDamage() + i);
		sep();
		p.beRepaired(5);
		sep();	
		p.printState();
		g.printState();
		m.printState();
		sep();
		++i;
	}
	return 0;
}
