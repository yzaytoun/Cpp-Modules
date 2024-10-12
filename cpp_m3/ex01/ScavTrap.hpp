/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
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

class ScavTrap : public ClapTrap
{
	public:
		ScavTrap(const std::string name);
		ScavTrap(const ScavTrap& scav);
		~ScavTrap(void);

		void	attack(const std::string& target);
		void	guardGate(void);
};

