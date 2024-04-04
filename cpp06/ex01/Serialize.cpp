/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serialize.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cafriem <cafriem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 14:16:23 by mkhan             #+#    #+#             */
/*   Updated: 2024/03/31 17:43:25 by cafriem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serialize.hpp"

Serialize::Serialize()
{
	std::cout << "Serialize Constructor Called" << std::endl;
}

Serialize::Serialize(Serialize const &a)
{
	std::cout << "Serialize Copy Constructor Called" << std::endl;
	*this = a;
}

Serialize &Serialize::operator=(Serialize const &rhs)
{
	std::cout << "Serialize Copy Assignment Operator = " << std::endl;
	if (this != &rhs)
	{
		// this = rhs;
	}
	return (*this);
}

Serialize::~Serialize()
{
	std::cout << "Serialize Destructor Called" << std::endl;
}

uintptr_t Serialize::serialize(Data *ptr)
{
	return(reinterpret_cast<uintptr_t>(ptr));
}

Data *Serialize::deserialize(uintptr_t raw)
{
	return(reinterpret_cast<Data *>(raw));
}
