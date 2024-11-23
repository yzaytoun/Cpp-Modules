/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 12:20:53 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/11/23 15:08:53 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

void	sep(void)
{
	std::cout << "-------------------------------" << std::endl;
}

int main( void )
{
	DiamondTrap	p("player");
	DiamondTrap	m("monster");
	DiamondTrap	g(p);

	sep();
	p.addDamagePower(2);
	m.addDamagePower(1);
	g.addDamagePower(100);
	g.highFivesGuys();
	sep();
	int	i = 0;
	while (i < 2)
	{
		sep();
		p.attack(m.getName());
		m.takeDamage(p.getDamage() + i);
		sep();
		g.attack(m.getName());
		m.takeDamage(g.getDamage() + i);
		sep();
		m.attack(p.getName());
		p.takeDamage(m.getDamage() + i);
		sep();
		p.beRepaired(5);
		sep();
		p.printState();
		g.printState();
		m.printState();
		sep();
		m.whoAmI();
		p.whoAmI();
		g.whoAmI();
		++i;
	}
	return 0;
}
