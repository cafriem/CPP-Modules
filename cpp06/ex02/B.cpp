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

#include "B.hpp"

B::B()
{
	std::cout << "B Constructor Called" << std::endl;
}

B::B(B const &object)
{
	std::cout << "B Copy Constructor Called" << std::endl;
	*this = object;
}

B &B::operator=(B const &rhs)
{
	std::cout << "B Copy Assignment Operator = " << std::endl;
	if (this != &rhs)
	{
		*this = rhs;
	}
	return (*this);
}

B::~B()
{
	std::cout << "B Destructor Called" << std::endl;
}
