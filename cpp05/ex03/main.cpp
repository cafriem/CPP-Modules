/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cafriem <cafriem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 17:39:03 by cafriem           #+#    #+#             */
/*   Updated: 2024/01/11 17:39:03 by cafriem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int main()
{
	std::string formName = "Robotomy"; 
	std::string formTarget = "garbage";
	Intern whocares;
	Bureaucrat bureaucrat("John", 1);
		std::cout << "------------------------------" << std::endl;
	AForm *f = whocares.makeForm(formName, formTarget);
		std::cout << "------------------------------" << std::endl;
	std::cout << *f;
	bureaucrat.signAForm(*f);
	std::cout << (*f).getSigned() << std::endl;
	bureaucrat.executeForm(*f);
	delete f;
}