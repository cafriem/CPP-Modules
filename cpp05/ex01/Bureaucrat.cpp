/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cafriem <cafriem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 09:01:58 by cafriem           #+#    #+#             */
/*   Updated: 2024/04/04 11:59:27 by cafriem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): _name("None"), _grade(75)
{
	std::cout << "Bureaucrat Constructor Called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade): _name(name), _grade(grade)
{
	std::cout << "Name Constructor Called" << std::endl;
	try
	{
		if (grade > 150)
			throw Bureaucrat::gradeTooLowExpectation();
		else if (grade < 1)
			throw Bureaucrat::gradeTooHighExpectation();
		else
			this->_grade = grade;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}

Bureaucrat::Bureaucrat(Bureaucrat const &object)
{
	std::cout << "Bureaucrat Copy Constructor Called" << std::endl;
	*this = object;
}

Bureaucrat& Bureaucrat::operator=(Bureaucrat const &rhs)
{
	std::cout << "Bureaucrat Copy Assignment == Operator" << std::endl;
	if (this != &rhs)
	{
		*this = rhs;
	}
	return(*this);
}

std::ostream &operator<<(std::ostream &out, Bureaucrat const &rhs)
{
	std::cout << "Bureaucrat Copy Assignment << Operator" << std::endl;
	try
	{
		if (rhs.getGrade() > 150)
			throw std::exception();
		else if (rhs.getGrade() < 1)
			throw std::exception();
		else
			out << rhs.getName() << ", Bureaucrat grade " << rhs.getGrade() << "." << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << "grade not in range" << std::endl;
	}
	return(out);
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat Destructor called" << std::endl;
}

std::string Bureaucrat::getName()const
{
	return(this->_name);
}

int	Bureaucrat::getGrade()const
{
	if (_grade < 1)
		throw Bureaucrat::gradeTooHighExpectation();
	if (_grade > 150)
		throw Bureaucrat::gradeTooLowExpectation();
	return(_grade);
}

const char* Bureaucrat::gradeTooHighExpectation::what() const throw()
{
	return("Bureaucrat Grade Too High");
}

const char* Bureaucrat::gradeTooLowExpectation::what() const throw()
{
	return("Bureaucrat Grade Too Low");
}

void	Bureaucrat::gradeIncreament()
{
	try
	{
		if (this->getGrade() >= 150)
			throw Bureaucrat::gradeTooLowExpectation();
		else if (this->getGrade() <= 1)
			throw Bureaucrat::gradeTooHighExpectation();
		else
			this->_grade--;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

void	Bureaucrat::gradeDecreament()
{
	try
	{
		if (this->getGrade() >= 150)
			throw Bureaucrat::gradeTooLowExpectation();
		else if (this->getGrade() <= 1)
			throw Bureaucrat::gradeTooHighExpectation();
		else
			this->_grade++;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

void	Bureaucrat::signForm(Form &form)
{
	try
	{
		form.beSigned(*this);
		std::cout << this->_name << " signed " << form.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << this->_name << "could't sign " << form.getName() <<
		" because " <<e.what() << '\n';
	}
	
}
