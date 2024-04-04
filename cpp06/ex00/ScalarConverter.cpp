/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cafriem <cafriem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 14:16:23 by mkhan             #+#    #+#             */
/*   Updated: 2024/03/31 17:43:25 by cafriem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
	std::cout << "ScalarConverter Constructor Called" << std::endl;
}

ScalarConverter::ScalarConverter(ScalarConverter const &a)
{
	std::cout << "ScalarConverter Copy Constructor Called" << std::endl;
	*this = a;
}

ScalarConverter & ScalarConverter::operator=(ScalarConverter const &rhs)
{
	std::cout << "ScalarConverter Copy Assignment Operator = " << std::endl;
	if (this != &rhs)
	{}
	return (*this);
}

ScalarConverter::~ScalarConverter()
{
	std::cout << "ScalarConverter Destructor Called" << std::endl;
}

void	ScalarConverter::isChar(std::string str)
{
	char ch = 0;
	try
	{
		if (str.length() == 1 && !isdigit(str[0]))
			ch = str[0];
		else
		{
			int	base = 10;
			char *endptr = NULL;
			const long long num = std::strtoll(str.c_str(), &endptr, base);
			if (endptr == str.c_str())
				throw std::invalid_argument("Not Conversionable");
			if (num < std::numeric_limits<int>::min() || num > std::numeric_limits<int>::max())
				throw std::out_of_range("out of range");
			ch = static_cast<char>(num);
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << "Char: Not Possible" << '\n';
		return ;
	}
	if (isprint(ch))
		std::cout << "Char: '" << ch << "'" << std::endl;
	else
		std::cout << "Char: Can't be Displayed" << std::endl;
}

void	ScalarConverter::isInt(std::string str)
{
	int	num = 0;
	try
	{
		if (str.length() == 1 && !isdigit(str[0]))
			num = static_cast<int>(str[0]);
		else
		{
			int	base = 10;
			char *endptr = NULL;
			const long long num2 = std::strtoll(str.c_str(), &endptr, base);
			if (endptr == str.c_str())
				throw std::invalid_argument("Not Conversionable");
			if (num2 < std::numeric_limits<int>::min() || num2 > std::numeric_limits<int>::max())
				throw std::out_of_range("out of range");
			num = static_cast<int>(num2);
		}
		std::cout << "Int: " << num << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Int: Not Possible" << '\n';
		return ;
	}
}

void	ScalarConverter::isFloat(std::string str)
{
	float num = 0;
	if (str.length() == 1 && !isdigit(str[0]))
		num = static_cast<float>(str[0]);
	else
		num = std::atof(str.c_str());
	if (num - static_cast<int>(num) != 0)
		std::cout << "Float: " << num << "f" << std::endl;
	else
		std::cout << "Float: " << num << ".0f" << std::endl;
}

void	ScalarConverter::isDouble(std::string str)
{
	double num = 0;
	if (str.length() == 1 && !isdigit(str[0]))
		num = static_cast<double>(str[0]);
	else
		num = std::atof(str.c_str());
	if (num - static_cast<int>(num) != 0)
		std::cout << "Double: " << num << std::endl;
	else
		std::cout << "Double: " << num << ".0" << std::endl;
}

void	ScalarConverter::convert(std::string str)
{
	isChar(str);
	isInt(str);
	isFloat(str);
	isDouble(str);
}
