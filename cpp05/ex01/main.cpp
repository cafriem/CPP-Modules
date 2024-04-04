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
	Bureaucrat bureaucrat1("Chris", 3);
	Bureaucrat bureaucrat2("Bob", 75);
	std::cout << bureaucrat1 << std::endl;
	std::cout << bureaucrat2 << std::endl;

	Form form1("Form1", 5, 10);
	std::cout << form1 << std::endl;
	bureaucrat1.signForm(form1);
	std::cout << form1 << std::endl;
	bureaucrat2.signForm(form1);
	std::cout << form1 << std::endl;

	Form form2("Form2", 8996, 10);
}
