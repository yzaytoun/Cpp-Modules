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

#include "iter.hpp"

int main( void )
{
	std::string	s_arr[3] = {"hola", "mola", "cola"};
	int			i_arr[3] = {1,2,3};
	double		d_arr[4] = {1.0,2.2,3.3,4.4};

	std::cout << "s_arr -> ";
	iter(s_arr, 3, print);
	std::cout << std::endl;
	std::cout << "i_arr -> ";
	iter(i_arr, 3, print);
	std::cout << std::endl;
	std::cout << "d_arr -> ";
	iter(d_arr, 3, print);
	std::cout << std::endl;
	return 0;
}
