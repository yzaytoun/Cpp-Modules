/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 15:43:53 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/08/13 12:51:32 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <optional>

/*
	Create zombie and calls announce
*/
void	randomChump(std::string name)
{
	Zombie	zombie(name);

	zombie.announce();
}
