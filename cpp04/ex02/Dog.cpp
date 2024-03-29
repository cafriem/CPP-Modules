/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cafriem <cafriem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 09:01:58 by cafriem           #+#    #+#             */
/*   Updated: 2024/01/11 17:30:13 by cafriem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : _brain(new Brain())
{
	std::cout << "Dog Constructor Called" << std::endl;
	this->type = "Dog";
}

Dog::Dog(Dog const &a): Animal(a)
{
	std::cout << "Dog Copy Constructor Called" << std::endl;
	*this = a;
}

Dog& Dog::operator=(Dog const &rhs)
{
	std::cout << "Dog Copy Assignment Operator" << std::endl;
	if (this != &rhs)
	{
		this->_brain = new Brain();
		this->_brain->setIdeas(rhs._brain->getIdeas());
		this->type = rhs.type;
	}
	return(*this);
}

Dog::~Dog()
{
	std::cout << "Dog Destructor Called" << std::endl;
	delete(this->_brain);
}

void	Dog::makeSound() const
{
	std::cout << "Bark" <<  std::endl;
}

std::string Dog::getType()const
{
	std::cout << "Dog getType() called" << std::endl;
	return(this->type);
}

Brain	*Dog::getBrain()const
{
	return(this->_brain);
}