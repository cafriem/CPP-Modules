/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cafriem <cafriem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 09:01:58 by cafriem           #+#    #+#             */
/*   Updated: 2024/01/08 03:48:45 by cafriem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default Constructor Called" << std::endl;
	this->_number = 0;
}

Fixed::Fixed(const int int_num)
{
	std::cout << "Int Constructor Called" << std::endl;
	this->_number = (int_num << this->_bit);
}

Fixed::Fixed(const float floatnum)
{
	std::cout << "Float Constructor Called" << std::endl;
	this->_number = roundf(floatnum * (1 << this->_bit));
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

float	Fixed::toFloat(void) const
{
	return(roundf(this->_number) / (1 << this->_bit));
}

int	Fixed::toInt(void) const
{
	return roundf(this->_number >> this->_bit);
}

std::ostream &operator<<(std::ostream &out, const Fixed &_number)
{
	out << _number.toFloat();
	return out;
}

//-----------------------bool funcs-------------------//

bool	Fixed::operator>(const Fixed& num1)
{
	return(this->_number > num1._number);
}

bool	Fixed::operator<(const Fixed& num1)
{
	return(this->_number < num1._number);
}

bool	Fixed::operator>=(const Fixed& num1)
{
	return(this->_number >= num1._number);
}

bool	Fixed::operator<=(const Fixed& num1)
{
	return(this->_number <= num1._number);
}

bool	Fixed::operator==(const Fixed& num1)
{
	return(this->_number == num1._number);
}

bool	Fixed::operator!=(const Fixed& num1)
{
	return !(*this == num1);
}

//-----------------------arethmatics funcs-------------------//

Fixed	Fixed::operator+(const Fixed& num1) const
{
	return(this->toFloat() + num1.toFloat());
}

Fixed	Fixed::operator-(const Fixed& num1) const
{
	return(this->toFloat() - num1.toFloat());
}

Fixed	Fixed::operator*(const Fixed& num1) const
{
	return(this->toFloat() * num1.toFloat());
}

Fixed	Fixed::operator/(const Fixed& num1) const
{
	return(this->toFloat() / num1.toFloat());
}

//-----------------------increments funcs-------------------//

Fixed&	Fixed::operator++()
{
	this->_number++;
	return(*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed	res(*this);
	this->_number++;
	return(res);
}

Fixed&	Fixed::operator--()
{
	this->_number--;
	return(*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed	res(*this);
	this->_number--;
	return(res);
}

//-----------------------min/max funcs-------------------//

Fixed&	Fixed::min(Fixed &a, Fixed &b)
{
	if (a < b)
		return(a);
	return(b);
}

Fixed&	Fixed::max(Fixed &a, Fixed &b)
{
	if (a > b)
		return(a);
	return(b);
}

const Fixed& Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a._number < b._number)
		return(a);
	return(b);
}

const Fixed& Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a._number > b._number)
		return(a);
	return(b);
}

Fixed::Fixed(const Fixed &a)
{
	std::cout << "Copy Constructor Called" << std::endl;
	*this = a;
}
