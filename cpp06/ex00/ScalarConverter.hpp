/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cafriem <cafriem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 11:05:51 by cafriem           #+#    #+#             */
/*   Updated: 2024/01/08 03:46:40 by cafriem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <iostream>
#include <cstdlib>
#include <string>

class ScalarConverter
{
	private:
		ScalarConverter();
		ScalarConverter(ScalarConverter const &object);
		ScalarConverter &operator=(ScalarConverter const &rhs);
		~ScalarConverter();

	public:
		static void	isChar(std::string str);
		static void	isInt(std::string str);
		static void	isFloat(std::string str);
		static void	isDouble(std::string str);
		static void	convert(std::string str);
};

#endif