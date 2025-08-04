/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 12:20:53 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/10/26 15:52:42 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include "easyfind.tpp"

std::string	bool_string(const bool val)
{
	if (val)
		return ("True");
	return ("False");
}

int main( void )
{
	std::map<std::string, int> mp;

	mp["Hola"] = 2;
	mp["mola"] = 21;

	std::cout << "---- Map ---- " << std::endl;
	std::cout << "Search for 21 -> " << bool_string(easyfind(mp, 21)) << std::endl;
	std::cout << "Search for 444 -> " << bool_string(easyfind(mp, 444)) << std::endl;
	
	std::vector<int>	vec;
	vec.push_back(1);
	vec.push_back(2);
	
	std::cout << "---- Vector ---- " << std::endl;
	std::cout << "Search for 1 -> " << bool_string(easyfind(vec, 1)) << std::endl;
	std::cout << "Search for 2 -> " << bool_string(easyfind(vec, 444)) << std::endl;
	return 0;
}
