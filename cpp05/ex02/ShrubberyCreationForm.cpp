/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cafriem <cafriem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 09:01:58 by cafriem           #+#    #+#             */
/*   Updated: 2024/03/25 00:47:15 by cafriem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string _target): AForm("ShrubberyCreationForm", 145, 137), _target(_target)
{
	std::cout << "ShrubberyCreationForm Constructor Called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &object): AForm(object), _target(object.getTarget())
{
	std::cout << "ShrubberyCreationForm Copy Constructor Called" << std::endl;
	*this = object;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &rhs)
{
	std::cout << "ShrubberyCreationForm Copy Assignment == Operator" << std::endl;
	if (this != &rhs)
	{
		AForm::operator=(rhs);
	}
	return(*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm Destructor called" << std::endl;
}

void	ShrubberyCreationForm::_asciiTree() const
{
	std::ofstream outfile;

	try
	{
		outfile.open((this->_target + "_shrubbery").c_str());
		if (outfile.fail())
			throw ShrubberyCreationForm::fileError();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	outfile << "   /\\    " << std::endl;
	outfile << "  /  \\   " << std::endl;
	outfile << " /    \\  " << std::endl;
	outfile << "/______\\ " << std::endl;
	outfile << "   ||    " << std::endl;
	outfile.close();
}

void	ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	try
	{
		if (this->getSigned())
		{
			if (executor.getGrade() <= this->getGradeExec())
			{
				this->_asciiTree();
				std::cout << this->getTarget() << "_shruberry tree has been created" << std::endl;
			}
			else
				throw AForm::gradeTooLowExpectation();
		}
		else
			throw std::out_of_range("Bureaucrat Form is not signed");
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

std::string ShrubberyCreationForm::getTarget() const
{
	return(this->_target);
}

const char	*ShrubberyCreationForm::fileError::what() const throw()
{
	return("Error : Couldn't Open/Create File");
}
