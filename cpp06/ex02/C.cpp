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

#include "C.hpp"

C::C()
{
	std::cout << "C Constructor Called" << std::endl;
}

C::C(C const &object)
{
	std::cout << "C Copy Constructor Called" << std::endl;
	*this = object;
}

C &C::operator=(C const &rhs)
{
	std::cout << "C Copy Assignment Operator = " << std::endl;
	if (this != &rhs)
	{
		*this = rhs;
	}
	return (*this);
}

C::~C()
{
	std::cout << "C Destructor Called" << std::endl;
}
