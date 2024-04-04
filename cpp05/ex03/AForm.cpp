/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cafriem <cafriem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 09:01:58 by cafriem           #+#    #+#             */
/*   Updated: 2024/03/25 15:11:45 by cafriem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(): _signed(false), _name("None"), _gradeSign(10), _gradeExecute(20)
{
	std::cout << "AForm Constructor Called" << std::endl;
}

AForm::AForm(std::string name, int _gradeSign, int _gradeExecute):
	_signed(false), _name(name), _gradeSign(_gradeSign), _gradeExecute(_gradeExecute)
{
	std::cout << "AForm Name Constructor Called" << std::endl;
	try
	{
		if (this->_gradeExecute > 150 || this->_gradeSign > 150)
			throw AForm::gradeTooLowExpectation();
		else if (this->_gradeExecute < 1 || this->_gradeSign < 1)
			throw AForm::gradeTooHighExpectation();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}

AForm::AForm(AForm const &object):
	_signed(object._signed), _name(object._name),
	_gradeSign(object._gradeSign), _gradeExecute(object._gradeExecute)
{
	std::cout << "AForm Copy Constructor Called" << std::endl;
	*this = object;
}

AForm& AForm::operator=(AForm const &rhs)
{
	std::cout << "AForm Copy Assignment == Operator" << std::endl;
	if (this != &rhs)
	{
		*this = rhs;
	}
	return(*this);
}

std::ostream &operator<<(std::ostream &out, AForm const &rhs)
{
	std::cout << "AForm Copy Assignment << Operator" << std::endl;
	out << "AForm name " << rhs.getName() << std::endl;
	out << "Grade Sign " << rhs.getGradeSign() << std::endl;
	out << "Grade Execute " << rhs.getGradeExec() << std::endl;
	out << "Signed " << rhs.getSigned() << std::endl;
	return(out);
}

AForm::~AForm()
{
	std::cout << "AForm Destructor called" << std::endl;
}

void	AForm::beSigned(Bureaucrat const &rhs)
{
	if (rhs.getGrade() > this->_gradeSign)
		throw AForm::gradeTooLowExpectation();
	else
		this->_signed = true;
}

bool	AForm::getSigned()const
{
	return(this->_signed);
}

std::string AForm::getName()const
{
	return(this->_name);
}

int	AForm::getGradeSign() const
{
	return(this->_gradeSign);
}

int	AForm::getGradeExec() const
{
	return(this->_gradeExecute);
}

const char* AForm::gradeTooHighExpectation::what() const throw()
{
	return("Grade Too High");
}

const char* AForm::gradeTooLowExpectation::what() const throw()
{
	return("Grade Too Low");
}
