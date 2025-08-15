/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 13:31:01 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/10/26 15:43:54 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <map>
#include <exception>
#include <ctime>
#include <fstream>

# define DATA_BASE_PATH "/data/data.csv"
# define RED	"\x1B[1;31m"
# define RESET	"\x1B[0m"

class BitcoinExchange
{
public:
	/* Type & Traits */
	typedef std::map<time_t, float>	DataBase;
	typedef struct Config
	{
		Config() : sep(' '), check_val(true), database(NULL) { }
		Config(const char separator, const bool check_value = true)
			: sep(separator) , check_val(check_value), database(NULL){ }

		char		sep;
		bool		check_val;
		DataBase*	database;
		bool		(*evalfunc)(const std::string&, Config&);
	} 			Config;
	

private:
	static void	parse(const std::string& file_path, BitcoinExchange::Config& conf);
public:
	BitcoinExchange();
	~BitcoinExchange();
	BitcoinExchange(const BitcoinExchange& bit);
	BitcoinExchange&	operator=(const BitcoinExchange& bit);
	
	static DataBase		buildDataBase(const std::string& db_path, BitcoinExchange::Config& conf);
	static void			evalRecords(const std::string& file_path, BitcoinExchange::Config& conf);

	/* Exceptions */
	class Exception : public std::exception
	{
		private:
			const char*	_message;
		public:
			Exception(const char* message) : _message(message) {}
			virtual	~Exception() throw() {}
			
			const char* what() const throw(){
				return (_message);
			};
	};
};
