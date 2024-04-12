/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cafriem <cafriem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 09:01:58 by cafriem           #+#    #+#             */
/*   Updated: 2024/03/25 00:47:15 by cafriem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern()
{
	std::cout << "Intern Constructor Called" << std::endl;
}

Intern::Intern(Intern const &object)
{
	std::cout << "Intern Copy Constructor Called" << std::endl;
	*this = object;
}

Intern& Intern::operator=(Intern const &rhs)
{
	std::cout << "Intern Copy Assignment == Operator" << std::endl;
	if (this != &rhs)
	{
		*this = rhs;
	}
	return(*this);
}

Intern::~Intern()
{
	std::cout << "Intern Destructor called" << std::endl;
}

AForm	*Intern::makeForm(std::string name, std::string target)
{
	std::string str[3] = {"President pardon", "Robotomy", "Shrubbery"};
	int	c = 0;
	while (name.empty() == false && c < 3 && name.compare(str[c]) != 0)
	{
		c++;
	}
	c++;
	switch (c)
	{
		case 1:
			return (new PresidentialPardonForm(target));
			break;
		case 2:
			return (new RobotomyRequestForm(target));
			break;
		case 3:
			return (new ShrubberyCreationForm(target));
			break;
		default:
			std::cout << "Intern can't make this form";
			break;
	}
	return(NULL);
}
