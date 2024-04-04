/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cafriem <cafriem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 09:01:58 by cafriem           #+#    #+#             */
/*   Updated: 2024/03/25 00:47:15 by cafriem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string _target): AForm("PresidentialPardonForm", 25, 5), _target(_target)
{
	std::cout << "PresidentialPardonForm Constructor Called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &object): AForm(object), _target(object.getTarget())
{
	std::cout << "PresidentialPardonForm Copy Constructor Called" << std::endl;
	*this = object;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(PresidentialPardonForm const &rhs)
{
	std::cout << "PresidentialPardonForm Copy Assignment == Operator" << std::endl;
	if (this != &rhs)
	{
		AForm::operator=(rhs);
	}
	return(*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "PresidentialPardonForm Destructor called" << std::endl;
}

void	PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	try
	{
		if (this->getSigned())
		{
			if (executor.getGrade() <= this->getGradeExec())
			{
				std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
			}
			else
				throw std::out_of_range("Bureaucrat grade is not enough");
		}
		else
			throw std::out_of_range("Bureaucrat Form is not signed");
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

std::string PresidentialPardonForm::getTarget() const
{
	return(this->_target);
}
