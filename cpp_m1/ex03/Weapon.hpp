/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 19:02:38 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/09/07 19:16:12 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

class Weapon
{
private:
	std::string		type;
public:
	Weapon(std::string type);
	~Weapon();
	std::string		getType();
	void			setType(std::string type);
};
