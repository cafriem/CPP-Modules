/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cafriem <cafriem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 09:01:58 by cafriem           #+#    #+#             */
/*   Updated: 2024/04/17 02:38:47 by cafriem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
	std::cout << "BitcoinExchange Constructor Called" << std::endl;
}

BitcoinExchange::BitcoinExchange(std::string  const filename): _filename(filename)
{
	std::cout << "Name Constructor Called" << std::endl;
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &object)
{
	std::cout << "BitcoinExchange Copy Constructor Called" << std::endl;
	*this = object;
}

BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange const &rhs)
{
	std::cout << "BitcoinExchange Copy Assignment == Operator" << std::endl;
	if (this != &rhs)
	{}
	return (*this);
}

BitcoinExchange::~BitcoinExchange()
{
	std::cout << "BitcoinExchange Destructor called" << std::endl;
}

const char* BitcoinExchange::FileIssues:: what(void) const throw()
{
	return (errorMessage.c_str());
}

BitcoinExchange::FileIssues::FileIssues(std::string error) : errorMessage(error) {};

BitcoinExchange::FileIssues::~FileIssues() throw() {};

std::string BitcoinExchange::getFilename(char* filename)
{
	std::string name = filename;
	this->_filename = name;
	return(this->_filename);
}

void BitcoinExchange::readDataFile()
{
	std::ifstream file("data.csv");
	if(file.fail())
		throw FileIssues("Cannot read the file");
	std::string line;
	getline(file, line);
	std::string key, date;
	while(getline(file,line))
	{
		std::stringstream ff(line);
		getline(ff, date, ',');
		getline(ff, key);
		this->_values[date] = atof(key.c_str());
	}
	file.close();
}

bool BitcoinExchange::checkforValues(std::string line)
{
	std::stringstream stream(line);
	std::string value;
	int valueCount = 0;  // Count of values

	while (getline(stream, value, ' '))
	{
		// Remove leading and trailing spaces from each value
		value.erase(value.find_last_not_of(" \t") + 1);
		value.erase(0, value.find_first_not_of(" \t"));

		// Check if the value contains only a single period ('.')
		if (value == ".")
		{
			std::cout << "Error: Cannot have only a '.' in the value" << std::endl;
			return false;
		}
		char *endptr;
		long number = strtol(value.c_str(), &endptr, 10);
		for (std::string::iterator it = value.begin(); it != value.end(); ++it)
		{
			if (!std::isdigit(*it) && *it != '.' && *it != '-' && *it != ' ')
			{
				std::cout << "Error: Invalid character '" << *it << "' found in value." << std::endl;
				return false;
			}
			if(std::count(value.begin(), value.end(), '.') > 2)
			{
				std::cout << "Error: Double decimal'" << *it << "' found in value." << std::endl;
				return false;
			}
		}
		if (number > 1000)
		{ 
			std::cout << "Error : Value number too large => " << number <<  std::endl;
			return false;
		}
		else if (number < 0)
		{ 
			std::cout << "Error : not a positive number => " << number << std::endl;
			return false;
		}
		valueCount++;
		if (valueCount > 1)
		{
			std::cout << "Error: More than one value found in the input" << std::endl;
			return false;
		}
	}

	return true;
}

bool BitcoinExchange::validDateFormat(std::string year,std::string month, std::string date)
{
	for (std::string::iterator it = year.begin(); it != year.end(); ++it)
	{
		if (!std::isdigit(*it))
		{
			std::cout << "Error: Invalid character '" << *it << "' found in value." << std::endl;
			return (false);
		}
	}
	for (std::string::iterator it = month.begin(); it != month.end(); ++it)
	{
		if (!std::isdigit(*it))
		{
			std::cout << "Error: Invalid character '" << *it << "' found in value." << std::endl;
			return (false);
		}
	}
	for (std::string::iterator it = date.begin(); it != date.end(); ++it)
	{
		if (!std::isdigit(*it))
		{
			std::cout << "Error: Invalid character '" << *it << "' found in value." << std::endl;
			return (false);
		}
	}
	return (true);
}

bool BitcoinExchange::checkforDates(std::string line)
{
	std::stringstream stream(line);
	std::string year, month, day;
		
	getline(stream, year, '-');
	getline(stream, month, '-');
	getline(stream, day);
		
	bool ValidDateFormat = validDateFormat(year, month, day);
	if(ValidDateFormat != false)
	{	
		int i_year = atoi(year.c_str());
		int i_month = atoi(month.c_str());
		int i_day = atoi(day.c_str());
		if((i_year % 4) == 0)
		{
			if(i_year < 2009 ||  i_year > 2022 ||year.size() > 4)
				{std::cout << "Error: Incorrect year => " << i_year << '-' << month << '-'<< day << std::endl; return (false);}
			else if (i_month < 1 || i_month > 12 || month.size() > 2)
				{std::cout << "Error: Incorrect month => " << year << '-' << month << '-'<< day << std::endl; return (false);}
			else if (i_day < 1 || i_day > 31 || day.size() > 3)
				{std::cout << "Error: Incorrect day => " << year << '-' << month << '-'<< day << std::endl; return(false);} 
			else if( i_month == 2 && i_day > 29)
				{std::cout << "Error: Leap Year is 29 days in Feburary => " << year << "-" << i_month << "-" << i_day << std::endl; return (false);}
		}
		else
		{
			if(i_year < 2009 || i_year > 2022 || year.size() > 4)
				{std::cout << "Error: Incorrect year => " << i_year << '-' << month << '-'<< day << std::endl; return (false);}
			else if (i_month < 1 || i_month > 12 || month.size() > 2)
				{std::cout << "Error: Incorrect month => " << i_year << '-' << month << '-'<< day<< std::endl; return (false);}
			else if (i_day < 1 || i_day > 31 || day.size() > 3)
				{std::cout << "Error: Incorrect day => " << i_year << '-' << month << '-'<< day << std::endl; return(false);} 
			else if(i_month == 2 && i_day > 28)
				{std::cout << "Error: Not a leap year which is 28 days in Feburary => " << i_year << "-" << i_month << "-" << i_day << std::endl; return (false);}
		}	
	}
	return (ValidDateFormat);
}

bool BitcoinExchange::checkforPair(std::string line)
{
	std::stringstream stream(line);
	std::string dates, value, pipe;
	getline(stream, dates, ' ');
	getline(stream, pipe, ' ');
	getline(stream, value);
	if(std::count(line.begin(), line.end(), '|') > 1 || std::count(line.begin(), line.end(), '|') == 0)
	{
		std::cout << "Error: bad input => " << line << std::endl;
		return (false);
	}
	else if(value.empty())
	{
		std::cout << "Error: Empty Value => " << line << std::endl;
		return (false);
	}
	return (true);
}

std::string BitcoinExchange::LowerBound(std::string &date)
{
	std::stringstream stream(date);
	std::string year, month, day, new_date;
	getline(stream, year, '-');
	int i_year = atoi(year.c_str());
	getline(stream, month, '-');
	int i_month = atoi(month.c_str());
	getline(stream, day);
	int i_day = atoi(day.c_str());
	if(i_day > 1)
		i_day--;
	else if(i_month > 1)
	{
		i_day = 31;
		i_month--;
	}
	else if(i_year > 2008)
	{
		i_day = 31;
		i_month = 12;
		i_year--;
	}
	std::stringstream copy_str;
	copy_str  << i_year << '-' << std::setw(2) << std::setfill('0') << i_month << '-' << std::setw(2) << std::setfill('0') << i_day;
	new_date = copy_str.str();
	return (new_date);
}

std::string BitcoinExchange::parseFilename(std::string const filename)
{
	if (filename.length() < 4)
		throw FileIssues("Filename is less than 4 characters");
	std::string checkFileName = filename.substr(filename.length() - 4, 4);
	if(checkFileName != ".txt" && checkFileName != ".csv")
		throw FileIssues("Filename does not cointain .txt/.csv");
	std::ifstream ifs(filename.c_str());
	if(!ifs)
		throw FileIssues("File does not exsist");
	std::ostringstream oss;
	std::string line;
	std::getline(ifs, line);
	if(line.compare("date | value") != 0)
	{
		ifs.close();
		throw FileIssues("Header not found [date | value]");
	}
	while(std::getline(ifs, line))
		oss << line << '\n';
	ifs.close();
	return (oss.str()); 
}

void BitcoinExchange::calculateValue(std::string &data)
{
	std::stringstream ff(data);
	std::string line;
	while(getline(ff, line, '\n'))
	{
		std::stringstream lol(line);
		std::string date, pipe, value;
		getline(lol, date, ' ');
		getline(lol, pipe, ' ');
		getline(lol, value);
		if(this->_values.end() == this->_values.find(date) )
		{
			if(this->checkforValues(value) && this->checkforDates(date) && this->checkforPair(line))
			{
				bool flag = this->checkforDates(date);	
				while(this->_values.find(date) == this->_values.end() && flag)
				{
					flag = this->checkforDates(date);
					date = this->LowerBound(date);
				}
				if(this->checkforValues(value) && flag && this->checkforPair(line))
				{
					std::cout << date  << " => " << atof(value.c_str()) << " = ";
					std::cout << this->_values[date] * atof(value.c_str()) << '\n';
				}
			}
		}
		else
		{
			if(this->checkforValues(value) && this->checkforDates(date) && this->checkforPair(line))
			{
				std::cout << date  << " => " << atof(value.c_str()) << " = ";
				std::cout << this->_values[date] * atof(value.c_str()) << '\n';
			}
		}
	}
}
