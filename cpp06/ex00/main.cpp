/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cafriem <cafriem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 17:39:03 by cafriem           #+#    #+#             */
/*   Updated: 2024/01/11 17:39:03 by cafriem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

bool	is_Char(std::string str)
{
	if (str.length() == 1 && (str != "nan" || str != "inff" || str != "-inff"
		|| str == "inf" || str == "-inf"))
		return(true);
	else if (str == "nan" || str == "inff" || str == "-inff"
		|| str == "inf" || str == "-inf")
		return(true);
	return(false);
}

bool	is_Int(std::string str)
{
	if ((str.find_first_not_of("123456789") == std::string::npos)
		|| (str.find_first_not_of("-123456789") == std::string::npos && str[0] == '-'))
		return(true);
	return(false);
}

bool	is_Float(std::string str)
{
	if ((str.find_first_not_of("123456789.f") == std::string::npos)
		|| (str.find_first_not_of("-123456789.f") == std::string::npos && str[0] == '-'))
		return(true);
	return(false);
}

bool	is_Double(std::string str)
{
	if ((str.find_first_not_of("123456789.") == std::string::npos)
		|| (str.find_first_not_of("-123456789.") == std::string::npos && str[0] == '-'))
		return(true);
	return(false);
}

bool	is_Convert(std::string str)
{
	if (is_Char(str) || is_Int(str) || is_Float(str) || is_Double(str))
		return(true);
	return(false);
}

int	main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cout << "Number of arguments." << std::endl;
		return(1);
	}
	if (is_Convert(argv[1]) && argv[1][0])
	{
		ScalarConverter::convert(argv[1]);
		return(0);
	}
	std::cout << "Invalid Arguement" << std::endl;
	return(1);
}
