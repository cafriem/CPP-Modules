/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cafriem <cafriem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 09:01:58 by cafriem           #+#    #+#             */
/*   Updated: 2024/01/05 12:12:03 by cafriem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{}

Fixed::~Fixed()
{
	std::cout << "destructor called" << std::endl;
}

void	Fixed::complain(std::string level)
{
	std::string	levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void	(Fixed::*ptrlevel[4])();
	ptrlevel[0] = &Fixed::debug;
	ptrlevel[1] = &Fixed::info;
	ptrlevel[2] = &Fixed::warning;
	ptrlevel[3] = &Fixed::error;
	for (int i = 0; i < 4; i++)
	{
		if (levels[i] == level)
		{
			(this->*ptrlevel[i])();
			return;
		}
	}
		
}
