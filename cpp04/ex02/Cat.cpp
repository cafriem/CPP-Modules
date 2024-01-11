/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cafriem <cafriem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 09:01:58 by cafriem           #+#    #+#             */
/*   Updated: 2024/01/11 13:53:49 by cafriem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal("Cat"), _brain(new Brain()) 
{
	std::cout << "Cat Constructor Called" << std::endl;
}

Cat::Cat(Cat const &a): Animal(a)
{
	std::cout << "Cat Copy Constructor Called" << std::endl;
	if (this != &a)
	{
		this->_brain = new Brain();
		this->_brain->setIdeas(a._brain->getIdeas());
		this->type = a.type;
	}
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
