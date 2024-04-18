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

#ifndef RPN_HPP
# define RPN_HPP

#include <map>
#include <cfloat>
#include <string>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <sys/stat.h>
#include <sys/types.h>

class	RPN
{
	private:
		std::stack<int> _number;

	public:
		RPN ();
		RPN (RPN const &object);
		RPN &operator=(RPN const &rhs);
		~RPN();

		int		calculate(int c, int c2, int flag);
		void	exec(char *str);
};

class	Errorclass: public std::exception
{
	public:
		const char *what() const throw();
};

enum	flag
{
	e_plus = '+',
	e_minus = '-',
	e_divide = '/',
	e_multiply = '*'
};

#endif
