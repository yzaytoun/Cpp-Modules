/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 12:20:53 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/10/12 18:28:43 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main( void )
{
	ClapTrap	p("player");
	ClapTrap	m("monster");

	p.addDamagePower(2);
	m.addDamagePower(1);
	int	i = 0;
	while (i < 2)
	{
		p.attack(m.getName());
		m.takeDamage(p.getDamage() + i);
		m.attack(p.getName());
		p.takeDamage(m.getDamage() + i);
		p.beRepaired(5);
		p.printEnergy();
		m.printEnergy();
		++i;
	}
	return 0;
}
