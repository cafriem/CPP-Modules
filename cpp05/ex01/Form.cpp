/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cafriem <cafriem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 09:01:58 by cafriem           #+#    #+#             */
/*   Updated: 2024/03/24 20:40:01 by cafriem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(): _signed(false), _name("None"), _gradeSign(10), _gradeExecute(20)
{
	std::cout << "Form Constructor Called" << std::endl;
}

Form::Form(std::string name, int _gradeSign, int _gradeExecute):
	_signed(false), _name(name), _gradeSign(_gradeSign), _gradeExecute(_gradeExecute)
{
	std::cout << "Form Name Constructor Called" << std::endl;
	try
	{
		if (this->_gradeExecute > 150 || this->_gradeSign > 150)
			throw Form::gradeTooLowExpectation();
		else if (this->_gradeExecute < 1 || this->_gradeSign < 1)
			throw Form::gradeTooHighExpectation();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}

Form::Form(Form const &object):
	_signed(object._signed), _name(object._name),
	_gradeSign(object._gradeSign), _gradeExecute(object._gradeExecute)
{
	std::cout << "Form Copy Constructor Called" << std::endl;
	*this = object;
}

Form& Form::operator=(Form const &rhs)
{
	std::cout << "Form Copy Assignment == Operator" << std::endl;
	if (this != &rhs)
	{
		*this = rhs;
	}
	return(*this);
}

std::ostream &operator<<(std::ostream &out, Form const &rhs)
{
	std::cout << "Form Copy Assignment << Operator" << std::endl;
	out << "Form name " << rhs.getName() << std::endl;
	out << "Grade Sign " << rhs.getGradeSign() << std::endl;
	out << "Grade Execute " << rhs.getGradeExec() << std::endl;
	out << "Signed " << rhs.getSigned() << std::endl;
	return(out);
}

Form::~Form()
{
	std::cout << "Form Destructor called" << std::endl;
}

void	Form::beSigned(Bureaucrat const &rhs)
{
	if (rhs.getGrade() > this->_gradeSign)
		throw Form::gradeTooLowExpectation();
	else
		this->_signed = true;
}

bool	Form::getSigned()const
{
	return(this->_signed);
}

std::string Form::getName()const
{
	return(this->_name);
}

int	Form::getGradeSign() const
{
	return(this->_gradeSign);
}

int	Form::getGradeExec() const
{
	return(this->_gradeExecute);
}

const char* Form::gradeTooHighExpectation::what() const throw()
{
	return("Grade Too High");
}

const char* Form::gradeTooLowExpectation::what() const throw()
{
	return("Grade Too Low");
}
