/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   A.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cafriem <cafriem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 14:16:23 by mkhan             #+#    #+#             */
/*   Updated: 2024/03/31 17:43:25 by cafriem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A.hpp"

A::A()
{
	std::cout << "A Constructor Called" << std::endl;
}

A::A(A const &object)
{
	std::cout << "A Copy Constructor Called" << std::endl;
	*this = object;
}

A &A::operator=(A const &rhs)
{
	std::cout << "A Copy Assignment Operator = " << std::endl;
	if (this != &rhs)
	{
		*this = rhs;
	}
	return (*this);
}

A::~A()
{
	std::cout << "A Destructor Called" << std::endl;
}
