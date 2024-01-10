/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhan <mkhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 15:30:26 by mkhan             #+#    #+#             */
/*   Updated: 2023/01/29 20:07:27 by mkhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(): _type("WrongCat")
{
	std::cout << "WrongCat Default Constructor called" << std::endl;
}


WrongCat::WrongCat(WrongCat const &object): WrongAnimal::WrongAnimal(object)
{
	std::cout << "WrongCat Copy Constructor called" << std::endl;
	*this = object;
}

WrongCat & WrongCat::operator=(WrongCat const &rhs)
{
	std::cout << "WrongCat Copy Assignment Operator called" << std::endl;
	if (this != &rhs)
		this->_type = rhs._type;
	return (*this);
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat Destructor called" << std::endl;
}

void	WrongCat::makeSound() const
{
	std::cout << "WrongCat::makeSound() called" << std::endl;
	std::cout << "WrongCat makes sound ... Bark" << std::endl;
}

std::string	WrongCat::getType() const
{
	std::cout << "WrongCat::getType() called" << std::endl;
	return (this->_type);
}