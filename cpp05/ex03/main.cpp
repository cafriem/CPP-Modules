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

int	main()
{
	Bureaucrat person1("Chris", 39);
	ShrubberyCreationForm form1("target");
	person1.signAForm(form1);
	person1.executeForm(form1);
	std::cout << "--------------------------------------------------------------" << std::endl;
	Bureaucrat person2("John", 19);
	RobotomyRequestForm form2("target");
	person2.signAForm(form2);
	person2.executeForm(form2);
	std::cout << "--------------------------------------------------------------" << std::endl;
	Bureaucrat person3("Bob",3);
	PresidentialPardonForm form3("target");
	person3.signAForm(form3);
	person3.executeForm(form3);
	std::cout << "--------------------------------------------------------------" << std::endl;
}