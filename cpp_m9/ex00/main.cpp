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
		BitcoinExchange::Config	config('|');
		BitcoinExchange::Config	database_config(',', false);
	
		BitcoinExchange::DataBase	source_data = BitcoinExchange::buildDataBase(DATA_BASE_PATH, database_config);
		config.database = &source_data;
		BitcoinExchange::evalRecords(argv[1], config);
	}
	else
		std::cerr << "One argument is requiered!!";
	return 0;
}
