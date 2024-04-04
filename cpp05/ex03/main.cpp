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

int	main()
{
	Bureaucrat B("john", 39);
	ShrubberyCreationForm A("target");
	B.signAForm(A);
	B.executeForm(A);
	std::cout << "--------------------------------------------------------------" << std::endl;
	Bureaucrat B("john", 19);
	RobotomyRequestForm A("target");
	B.signAForm(A);
	B.executeForm(A);
	std::cout << "--------------------------------------------------------------" << std::endl;
	Bureaucrat B("john",3);
	PresidentialPardonForm A("target");
	B.signAForm(A);
	B.executeForm(A);
}