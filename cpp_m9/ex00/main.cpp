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

#include "BitcoinExchange.hpp"

int main(int argc, char** argv)
{
	if (argc == 2)
	{
		BitcoinExchange::DataBase	source_data = BitcoinExchange::buildDataBase(DATA_BASE_PATH);
		BitcoinExchange::DataBase	data = BitcoinExchange::buildDataBase(argv[1]);
		// Find date
		// Count
	}
	else
		std::cerr << "One argument is requiered!!";
	return 0;
}
