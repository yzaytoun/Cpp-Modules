/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 18:36:23 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/10/12 19:41:56 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>
#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap
{
	private:
		std::string	_name;
		int			_hit_points;
		int			_energy_points;
		int			_attack_damage;

	public:
		DiamondTrap(const std::string name);
		DiamondTrap(const DiamondTrap& scav);
		~DiamondTrap(void);

		void		attack(const std::string& target);
		std::string	getName(void);
		void		whoAmI(void);
};
