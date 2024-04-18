/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cafriem <cafriem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 09:01:58 by cafriem           #+#    #+#             */
/*   Updated: 2024/04/18 12:58:55 by cafriem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN()
{
	std::cout << "RPN Constructor Called" << std::endl;
}

RPN::RPN(RPN const &object)
{
	std::cout << "RPN Copy Constructor Called" << std::endl;
	if (this != &object)
	{
		this->_number = object._number;
	}
}

RPN &RPN::operator=(RPN const &rhs)
{
	std::cout << "RPN Copy Assignment == Operator" << std::endl;
	if (this != &rhs)
	{
		this->_number = rhs._number;
	}
	return (*this);
}

RPN::~RPN()
{
	std::cout << "RPN Destructor called" << std::endl;
}

int	RPN::calculate(int c, int c2, int flag)
{
	switch (flag)
	{
		case e_plus:
			return (c + c2);
		case e_minus:
			return (c - c2);
		case e_multiply:
			return (c * c2);
		case e_divide:
		{
			if (c2 != 0)
			{
				std::cout << "A number can not be divided by zero" << std::endl;
				return (0);
			}
			else
				return (c / c2);
		}
	}
	return (0);
}

void	RPN::exec(char *str)
{
	std::string			n_str;
	std::string			before;

	n_str = str;
	if (n_str.empty() || n_str.find_first_not_of("1234567890+-/* ") != std::string::npos)
		throw (Errorclass());
	std::stringstream	c_str;
	c_str << str;
	int			num2;
	int			num1;
	char		flag;
	while (c_str >> n_str)
	{
		if (n_str.size() > 1)
			throw (Errorclass());
		before = n_str;
		if (n_str.find_first_not_of("1234567890") == std::string::npos)
			_number.push(atoi(n_str.c_str()));
		if (n_str.find_first_of("+-/*") != std::string::npos && _number.size() < 2)
			throw (Errorclass());
		if (n_str.find_first_of("+-/*") != std::string::npos && _number.size() >= 2)
		{
			num2 = _number.top();
			_number.pop();
			num1 = _number.top();
			_number.pop();
			flag = (int)n_str[0];
			_number.push(this->calculate(num1, num2, flag));
		}
	}
	if (_number.size() >= 2 || _number.size() == 0
		|| n_str.find_first_not_of("1234567890") == std::string::npos)
		throw (Errorclass());
	std::cout << _number.top() << std::endl;
}

const char	*Errorclass::what() const throw()
{
	return ("Error");
}
