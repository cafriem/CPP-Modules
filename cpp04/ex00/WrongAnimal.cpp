/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cafriem <cafriem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 09:01:58 by cafriem           #+#    #+#             */
/*   Updated: 2024/01/10 08:29:54 by cafriem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("WrongAnimal")
{
	std::cout << "WrongAnimal Constructor Called" << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const &a)
{
	std::cout << "WrongAnimal Copy Constructor Called" << std::endl;
	*this = a;
}

WrongAnimal& WrongAnimal::operator=(WrongAnimal const &rhs)
{
	std::cout << "WrongAnimal Copy Assignment Operator = " << std::endl;
	if (this != &rhs)
		this->type = rhs.type;
	return(*this);
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal Destructor Called" << std::endl;
}

void	WrongAnimal::makeSound() const
{
	std::cout << "WrongAnimal sound" <<  std::endl;
}

std::string WrongAnimal::getType()const
{
	std::cout << "WrongAnimal getType() called" << std::endl;
	return(this->type);
}
