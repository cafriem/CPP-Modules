/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cafriem <cafriem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 09:01:58 by cafriem           #+#    #+#             */
/*   Updated: 2024/01/10 12:04:24 by cafriem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : _brain(new Brain()), type("Cat")
{
	std::cout << "Cat Constructor Called" << std::endl;
}

Cat::Cat(Cat const &a): Animal(a)
{
	std::cout << "Cat Copy Constructor Called" << std::endl;
	*this = a;
}

Cat& Cat::operator=(Cat const &rhs)
{
	std::cout << "Cat Copy Assignment Operator" << std::endl;
	if (this != &rhs)
	{
		this->_brain = new Brain();
		this->_brain->setIdeas(rhs._brain->getIdeas());
		this->type = rhs.type;
	}
	return(*this);
}

Cat::~Cat()
{
	std::cout << "Cat Destructor Called" << std::endl;
	delete(this->_brain);
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

Brain	*Cat::getBrain()const
{
	return(this->_brain);
}
