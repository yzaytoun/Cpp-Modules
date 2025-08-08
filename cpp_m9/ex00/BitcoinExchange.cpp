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
	if (strarray && !(*strarray)->empty())
	{
		delete[] *strarray;
		*strarray = NULL;
	}
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

static std::string*	split(const std::string& str, const char c)
{
	std::string::const_iterator	it;
	std::string::const_iterator	cleaned_it;
	std::size_t		len = std::count(str.begin(), str.end(), c) + 1;
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
		cleaned_it = std::remove(strarray[idx].begin(), strarray[idx].end(), ' ');
		strarray[idx].erase(cleaned_it, strarray[idx].end());
	}
	if (strarray[0].empty())
		strarray[0] = str;
	return (strarray);
}

bool	evalHeader(const std::string& header, const char sep)
{
	std::string*	strarray = split(header, sep);
	bool			result = false;

	if (strArrLength(strarray) == 2)
		result = (evalString(strarray[0], isalpha_hyphen)
					&& evalString(strarray[1], isalpha_hyphen));
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
	return (std::stof(float_string));
}

bool	inRange(const int value, const int min, const int max, bool inclusive = true)
{
	if (inclusive)
		return (value >= min && value <= max);
	return (value > min && value < max);
}

std::string	dateToString(const struct tm* datetime)
{
	char buffer[32];

	std::strftime(buffer, 32, "%Y-%m-%d", datetime);
	return (buffer);
}

std::string	dateToString(const time_t* time)
{
	struct tm*	datetime = std::localtime(time);
	char		buffer[32];

	std::strftime(buffer, 32, "%Y-%m-%d", datetime);
	return (buffer);
}

static time_t	toDateTime(const std::string& date_string)
{
	struct tm*		datetime = new struct tm();
	time_t			rawtime = 0;
	bool			is_valid = true;
	std::string*	strarray = split(date_string, '-');
	int*			values[3];
	int		ranges[3][3] = {
		{INT_MIN, INT_MAX, 1900},
		{0, 11, 1},
		{1, 31, 0}
	};

	values[0] = &datetime->tm_year;
	values[1] = &datetime->tm_mon;
	values[2] = &datetime->tm_mday;
	if (strArrLength(strarray) == 3)
	{
		for (int i = 0; i < 3; i++)
		{
			*values[i] = std::stoi(strarray[i]) - ranges[i][2];
			is_valid = inRange(*values[i], ranges[i][0], ranges[i][1]);
			if (!is_valid)
				break;
		}
		rawtime = mktime(datetime);
	}
	//std::cout << "datetime -> " << dateToString(datetime) << std::endl;
	//std::cout << "rawtime -> " << dateToString(&rawtime) << std::endl;
	deleteArray(&strarray);
	delete datetime;
	if (!is_valid)
		throw BitcoinExchange::Exception("Bad date format");
	return(rawtime);
}

/*
	Parser
*/

static bool	parse(const std::string& content, BitcoinExchange::DataBase& db, BitcoinExchange::Config conf)
{
	bool			result = false;
	std::string*	strarray = split(content, conf.sep);
	time_t			_date;
	float			_value;

	_date = toDateTime(strarray[0]);
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

BitcoinExchange::DataBase	BitcoinExchange::parseCSV(const std::string& file_path, BitcoinExchange::Config conf)
{
	std::ifstream				file(file_path);
	std::string					content;
	BitcoinExchange::DataBase 	db;
	int	record_count = 0;

	if (file.is_open())
	{
		while (!file.eof())
		{
			std::getline(file, content);
			if (!content.empty())
			{
				if (record_count && !parse(content, db, conf))
					throw BitcoinExchange::Exception("Bad File");
				else if (!record_count)
					evalHeader(content, conf.sep);
				++record_count;
			}
		}
		file.close();
	}
	return (db); 
}

/*
	Converts a CSV file to a DataBase object
*/
BitcoinExchange::DataBase	BitcoinExchange::buildDataBase(const std::string& db_path, BitcoinExchange::Config conf)
{
	DataBase	db;

	try
	{
		db = BitcoinExchange::parseCSV(db_path, conf);
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
