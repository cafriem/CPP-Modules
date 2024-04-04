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

#ifndef FORM_HPP
# define FORM_HPP

#include "Bureaucrat.hpp"

class	Bureaucrat;
class	Form
{
	private:
		bool				_signed;
		const std::string	_name;
		const int			_gradeSign;
		const int			_gradeExecute;

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
		Form();
		Form(const std::string name, const int gradsign, const int gradeExecution);
		Form(const Form& object);
		Form &operator=(const Form &rhs);
		~Form();

		bool		getSigned() const;
		void		beSigned(Bureaucrat const &rhs);
		std::string	getName() const;
		int			getGradeSign() const;
		int			getGradeExec() const;
};

std::ostream &operator<<(std::ostream &out, Form const &rhs);

#endif
