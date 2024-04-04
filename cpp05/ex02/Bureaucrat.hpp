/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cafriem <cafriem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 11:05:51 by cafriem           #+#    #+#             */
/*   Updated: 2024/01/08 03:46:40 by cafriem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include "AForm.hpp"

class	AForm;
class	Bureaucrat
{
	private:
		const std::string	_name;
		int					_grade;

		class gradeTooLowExpectation : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

		class gradeTooHighExpectation : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

	public:
		Bureaucrat();
		Bureaucrat(std::string name, int grade);
		Bureaucrat(Bureaucrat const &object);
		Bureaucrat &operator=(Bureaucrat const &rhs);
		~Bureaucrat();

		std::string	getName() const;
		int			getGrade() const;
		void		gradeIncreament();
		void		gradeDecreament();
		void		signAForm(AForm &Aform);
		void		executeForm(AForm const &Aform);
};

std::ostream &operator<<(std::ostream &out, Bureaucrat const &rhs);

#endif
