/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 19:06:49 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/09/19 12:42:14 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include "Weapon.hpp"

class HumanA
{
private:
	std::string		name;
	Weapon			&weapon;
public:
	HumanA(std::string name, Weapon& weapon);
	~HumanA();

	void	attack(void);
};
