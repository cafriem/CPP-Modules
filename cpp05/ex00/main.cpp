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
	std::cout << "Test" << std::endl;
	Bureaucrat test1 = Bureaucrat("Chris", 1);
	Bureaucrat test2 = Bureaucrat("Bob", 75);
	Bureaucrat test3 = Bureaucrat("John", 150);
	test2.gradeIncreament();
	test2.gradeIncreament();
	std::cout << test2;
	test3.gradeDecreament();
	test3.gradeDecreament();
	std::cout << test3;

	std::cout << "Fail Test" << std::endl;
	Bureaucrat test4 = Bureaucrat("Chris", -5);
	Bureaucrat test6 = Bureaucrat("John", 170);
}
