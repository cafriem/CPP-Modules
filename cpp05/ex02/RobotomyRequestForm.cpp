/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cafriem <cafriem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 09:01:58 by cafriem           #+#    #+#             */
/*   Updated: 2024/03/25 00:47:15 by cafriem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string _target): AForm("RobotomyRequestForm", 72, 45), _target(_target)
{
	std::cout << "RobotomyRequestForm Constructor Called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &object):
	AForm(object), _target(object.getTarget())
{
	std::cout << "RobotomyRequestForm Copy Constructor Called" << std::endl;
	*this = object;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(RobotomyRequestForm const &rhs)
{
	std::cout << "RobotomyRequestForm Copy Assignment == Operator" << std::endl;
	if (this != &rhs)
	{
		AForm::operator=(rhs);
	}
	return(*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm Destructor called" << std::endl;
}

void	RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	try
	{
		if (this->getSigned())
		{
			if (executor.getGrade() <= this->getGradeExec())
			{
				srand(time(NULL));
				if (rand() % 2)
				{
					std::cout << "*drilling noises*" << std::endl;
					std::cout << this->_target << " has been robotomized" << std::endl;
				}
				else
					std::cout << "robotomy failed" << std::endl;
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

std::string RobotomyRequestForm::getTarget() const
{
	return(this->_target);
}
