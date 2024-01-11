/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cafriem <cafriem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 09:01:58 by cafriem           #+#    #+#             */
/*   Updated: 2024/01/10 07:57:12 by cafriem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	std::cout << "WrongCat Constructor Called" << std::endl;
	this->type = "WrongCat";
}

WrongCat::WrongCat(WrongCat const &a)  : WrongAnimal(a)
{
	std::cout << "WrongCat Copy Constructor Called" << std::endl;
	*this = a;
}

WrongCat& WrongCat::operator=(WrongCat const &rhs)
{
	std::cout << "WrongCat Copy Assignment Operator = " << std::endl;
	if (this != &rhs)
		this->type = rhs.type;
	return(*this);
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat Destructor Called" << std::endl;
}

void	WrongCat::makeSound() const
{
	std::cout << "Bark! (wrong cat sounds)" <<  std::endl;
}

std::string WrongCat::getType()const
{
	std::cout << "WrongCat getType() called" << std::endl;
	return(this->type);
}
