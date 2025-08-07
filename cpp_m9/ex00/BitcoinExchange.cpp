/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 13:29:49 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/10/26 15:42:50 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& bit) {(void)bit;}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange&	BitcoinExchange::operator=(const BitcoinExchange& bit) {(void)bit;	return (*this);}

/*
	Utils
*/

bool	isValidValue(const float& value)
{
	return (value >= 0 && value <= 1000);
}

int		isalpha_hyphen(const int chr)
{
	return (std::isalpha(chr) || chr == '_');
}

void	deleteArray(std::string** strarray)
{
	if (strarray && *strarray)
	{
		delete[] *strarray;
		*strarray = NULL;
	}
}

static char	getSplitChar(const std::string& str, const std::string& pattern)
{
	std::string::const_iterator	it;

	for (it = pattern.begin(); it != pattern.end(); it++)
	{
		if (str.find(*it) != std::string::npos)
			break;
	}
	return (*it);
}

static bool	evalString(const std::string& str, int (*func)(int))
{
	std::string::const_iterator	it;
	bool	result = true;

	for (it = str.begin(); it != str.end(); ++it)
	{
		if (!func(*it))
		{
			result = false;
			break;
		}
	}
	return (result);
}

int strArrLength(const std::string* strarray)
{
	std::string const*	ptr = strarray;
	int					count = 0;

	while (*ptr != "")
	{
		++ptr;
		++count;
	}
	return (count);
}

std::size_t	countChr(const std::string& str, const int chr)
{
	std::string::const_iterator	it;
	std::size_t	count = 0;

	for (it = str.begin(); it != str.end(); it++)
	{
		if (*it == chr)
			++count;
	}
	return (count);
}

static std::string*	split(const std::string& str, const std::string& pattern)
{
	std::string::const_iterator	it;
	char			c = getSplitChar(str, pattern);
	std::size_t		len = countChr(str, c) + 1;
	std::string*	strarray = new std::string[len];
	std::size_t		start = 0;
	std::size_t		end = 0;

	for (std::size_t idx = 0; idx < len; ++idx)
	{
		end = str.find(c, start);
		if (end != std::string::npos)
		{
			strarray[idx] = str.substr(start, end - start);
			start = end + 1;
		}
		else if (start)
			strarray[idx] = str.substr(start);
	}
	return (strarray);
}

bool	evalHeader(const std::string& header)
{
	std::string*	strarray = split(header, "|,");
	bool			result = false;

	if (strArrLength(strarray) == 2)
			result = (evalString(strarray[0], isalpha_hyphen) && evalString(strarray[1], isalpha_hyphen));
	else
		throw BitcoinExchange::Exception("Invalid header");
	deleteArray(&strarray);
	return (result);
}

/*
	Converters 
*/

static float	toFloat(const std::string& float_string)
{
	float	num = -1;

	num = std::stof(float_string);
	if (isValidValue(num))
		throw BitcoinExchange::Exception("Bad value");
	return (num);
}

static time_t	toDateTime(const std::string& date_string)
{
	struct tm		datetime;
	time_t			time = 0;
	bool			is_valid = true;
	std::string*	strarray = split(date_string, "-");

	if (strArrLength(strarray) == 3)
	{
		datetime.tm_year = std::stoi(strarray[0]);
		is_valid = inRange(datetime.tm_year, 0, 365);
		datetime.tm_mon = std::stoi(strarray[1]);
		datetime.tm_mday = std::stoi(strarray[2]);
		time = mktime(&datetime);
	}
	deleteArray(&strarray);
	if (!is_valid)
		throw BitcoinExchange::Exception("Bad date format");
	return(time);
}

/*
	Parser
*/

static bool	parse(const std::string& content, BitcoinExchange::DataBase& db)
{
	bool			result = false;
	std::string*	strarray = split(content, "|,");
	time_t			_date;
	float			_value;

	if (strArrLength(strarray) == 2)
	{
		_date = toDateTime(strarray[0]);
		_value = toFloat(strarray[1]);
		db[_date] = _value;
		result = true;
	}
	deleteArray(&strarray);
	return (result);
}

BitcoinExchange::DataBase	BitcoinExchange::parseCSV(const std::string& file_path)
{
	std::ifstream				file;
	std::string					content;
	BitcoinExchange::DataBase 	db;
	int	record_count = 0;

	file.open(file_path);
	if (file.is_open())
	{
		while (!file.eof())
		{
			file >> content;
			std::cout << content << std::endl;
			if (record_count && !parse(content, db))
				throw BitcoinExchange::Exception("Bad File");
			else if (!record_count)
				evalHeader(content);
			++record_count;
		}
		file.close();
	}
	return (db); 
}

/*
	Converts a CSV file to a DataBase object
*/
BitcoinExchange::DataBase	BitcoinExchange::buildDataBase(const std::string& db_path)
{
	DataBase	db;

	try
	{
		db = BitcoinExchange::parseCSV(db_path);
		if (db.empty())
			throw BitcoinExchange::Exception("Empty Database");
	}
	catch(const std::exception& e)
	{
		std::cerr << RED "Exception: " RESET << e.what() << '\n';
		exit(EXIT_FAILURE);
	}
	return (db);
}
