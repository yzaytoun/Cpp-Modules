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

#include "PmergeMe.hpp"

int main(int argc, const char** argv)
{
	if (argc > 1)
	{
		try
		{
			PmergeMe<>					def;
			PmergeMe<std::list<int> >	lst;
			PmergeMe<std::deque<int> >	dq;

			def.sort(argc ,argv);
			lst.sort(argc, argv);
			dq.sort(argc, argv);
		}
		catch(const std::exception& e)
		{
			std::cerr << "Error: " << e.what() << '\n';
		}
	}
	else
	{
		std::cerr << "More than one argument is requiered!!" << std::endl;
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
