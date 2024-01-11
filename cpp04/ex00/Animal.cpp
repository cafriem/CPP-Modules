/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cafriem <cafriem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 09:01:58 by cafriem           #+#    #+#             */
/*   Updated: 2024/01/11 17:18:47 by cafriem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : type("Animal")
{
	std::cout << "Animal Constructor Called" << std::endl;
}

Animal::Animal(Animal const &a)
{
	std::cout << "Animal Copy Constructor Called" << std::endl;
	*this = a;
}

Animal& Animal::operator=(Animal const &rhs)
{
	std::cout << "Animal Copy Assignment Operator = " << std::endl;
	if (this != &rhs)
		this->type = rhs.type;
	return(*this);
}

Animal::~Animal()
{
	std::cout << "Animal Destructor Called" << std::endl;
}

void	Animal::makeSound() const
{
	std::cout << "Animal sounds" <<  std::endl;
}

std::string Animal::getType()const
{
	std::cout << "Animal getType() called" << std::endl;
	return(this->type);
}
