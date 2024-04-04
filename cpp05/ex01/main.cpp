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

int	main()
{
	Bureaucrat bureaucrat1("Person1", 3);
	Bureaucrat bureaucrat2("Person2", 75);
	std::cout << bureaucrat1 << std::endl;
	std::cout << bureaucrat2 << std::endl;
	Form form1("Form1", 5, 10);
	std::cout << "--------------------------------------------------------------" << std::endl;
	std::cout << form1 << std::endl;
	std::cout << "--------------------------------------------------------------" << std::endl;
	try {
		Form form2("Form1", 8996, 10);
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << "--------------------------------------------------------------" << std::endl;
	try {
		bureaucrat1.signForm(form1);
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << form1 << std::endl;
	std::cout << "--------------------------------------------------------------" << std::endl;
	try {
		bureaucrat2.signForm(form1);
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << form1 << std::endl;
	return 0;
}
