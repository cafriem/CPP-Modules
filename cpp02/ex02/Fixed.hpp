/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cafriem <cafriem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 11:05:51 by cafriem           #+#    #+#             */
/*   Updated: 2024/01/08 03:46:40 by cafriem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	FIXED_HPP
# define FIXED_HPP


#include <iostream>
#include <string>
#include <stdlib.h>
#include <iomanip>
#include <limits>
#include <cmath>

class	Fixed
{
	private:
		int					_number;
		static const int	_bit = 8;

	public:
		Fixed();
		Fixed(const Fixed &a);
		Fixed& operator=(const Fixed&rhs);
		Fixed(const int int_num);
		Fixed(const float floatnum);
		~Fixed();

		int		getRawBits(void)const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;

		bool	operator>(const Fixed& num1);
		bool	operator<(const Fixed& num1);
		bool	operator>=(const Fixed& num1);
		bool	operator<=(const Fixed& num1);
		bool	operator==(const Fixed& num1);
		bool	operator!=(const Fixed& num1);

		Fixed	operator+(const Fixed& num1)const;
		Fixed	operator-(const Fixed& num1)const;
		Fixed	operator*(const Fixed& num1)const;
		Fixed	operator/(const Fixed& num1)const;

		Fixed&	operator++();
		Fixed	operator++(int);
		Fixed&	operator--();
		Fixed	operator--(int);

		static Fixed&		min(Fixed &a, Fixed &b);
		static Fixed&		max(Fixed &a, Fixed &b);
		const static Fixed&	min(const Fixed &a, const Fixed &b);
		const static Fixed&	max(const Fixed &a, const Fixed &b);

};
	std::ostream &operator<<(std::ostream &out, const Fixed &_number);

#endif
