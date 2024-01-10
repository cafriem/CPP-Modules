/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cafriem <cafriem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 09:01:58 by cafriem           #+#    #+#             */
/*   Updated: 2024/01/10 07:57:12 by cafriem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : type("Cat")
{
	std::cout << "Cat Constructor Called" << std::endl;
}

Cat::Cat(Cat const &a)
{
	std::cout << "Cat Copy Constructor Called" << std::endl;
	*this = a;
}

Cat& Cat::operator=(Cat const &rhs)
{
	std::cout << "Cat Copy Assignment Operator = " << std::endl;
	if (this != &rhs)
		this->type = rhs.type;
	return(*this);
}

Cat::~Cat()
{
	std::cout << "Cat Destructor Called" << std::endl;
}

void	Cat::makeSound() const
{
	std::cout << "Meow" <<  std::endl;
}

std::string Cat::getType()const
{
	std::cout << "Cat getType() called" << std::endl;
	return(this->type);
}
