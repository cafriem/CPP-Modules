/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cafriem <cafriem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 09:01:58 by cafriem           #+#    #+#             */
/*   Updated: 2024/01/08 01:46:55 by cafriem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default Constructor Called" << std::endl;
	this->_number = 0;
}

Fixed::Fixed(const Fixed &a)
{
	std::cout << "Copy Constructor Called" << std::endl;
	*this = a;
}

Fixed& Fixed::operator=(const Fixed&rhs)
{
	std::cout << "Copy Assignment Operator Called" << std::endl;
	this->_number = rhs.getRawBits();
	return(*this);
}

Fixed::~Fixed()
{
	std::cout << "Destructor Called" << std::endl;
}

int	Fixed::getRawBits(void)const
{
	std::cout << "getRawBits() member function called" << std::endl;
	return(this->_number);
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits() member function called" << std::endl;
	this->_number = raw;
}
