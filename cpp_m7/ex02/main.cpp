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

#include "Array.hpp"
#include "Array.tpp"

int main( void )
{
	Array<int> arr(10);
	for (size_t i = 0; i < 5; i++)
		arr[i] = i;
	arr.iter(print);
	std::cout << std::endl;
	
	try{
		(void)arr[333];
	}
	catch(std::logic_error& e)
	{
		std::cerr << "Exception-> " << e.what() << std::endl;
	}
	// --------------- Copy -----------------------
	Array<int>	arr_1(3);
	Array<int>	arr_2(5);
	for (size_t i = 0; i < 3; i++)
		arr_1[i] = i;
	for (size_t i = 0; i < 5; i++)
		arr_2[i] = i;
	arr_1 = arr_2;	
	arr_1.iter(print);
	// --------------- Overriding new -----------------------
	Array<std::string>*	arr2 = new Array<std::string>[10];

	arr2[1][0] = "10";

	delete[] arr2;
	return 0;
}
