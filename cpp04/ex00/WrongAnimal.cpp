/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhan <mkhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 15:28:09 by mkhan             #+#    #+#             */
/*   Updated: 2023/01/29 20:05:32 by mkhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(): _type("WrongAnimal")
{
	std::cout << "WrongAnimal Default Constructor called" << std::endl;
}


WrongAnimal::WrongAnimal(WrongAnimal const &object)
{
	std::cout << "WrongAnimal Copy Constructor called" << std::endl;
	*this = object;
}

WrongAnimal & WrongAnimal::operator=(WrongAnimal const &rhs)
{
	std::cout << "WrongAnimal Copy Assignment Operator called" << std::endl;
	if (this != &rhs)
		this->_type = rhs._type;
	return (*this);
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal Default Destructor called" << std::endl;
}

void	WrongAnimal::makeSound() const
{
	std::cout << "WrongAnimal::makeSound() called" << std::endl;
	std::cout << "WrongAnimal makes sound ..." << std::endl;
}

std::string WrongAnimal::getType() const
{
	std::cout << "WrongAnimal::getType() called" << std::endl;
	return (this->_type);
}