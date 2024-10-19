/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 18:42:46 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/10/18 19:34:22 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>

class ClapTrap
{
	private:
		std::string	_name;
		int			_hit_points;
		int			_energy_points;
		int			_attack_damage;

	public:
		ClapTrap(const std::string name);
		ClapTrap(const std::string name, int hit_points, int energy_points, int damage_power);
		ClapTrap(const ClapTrap& clap);
		~ClapTrap(void);
	
		ClapTrap&	operator=(const ClapTrap& clap);

		std::string	getName(void) const;
		int			getDamage(void) const;
		void		printEnergy(void) const;
			
		void		attack(const std::string& target);
		void		takeDamage(unsigned int amount);
		void		beRepaired(unsigned int amount);
		void		addDamagePower(unsigned int amount);
};
