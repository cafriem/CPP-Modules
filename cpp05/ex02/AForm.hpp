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

#ifndef AFORM_HPP
# define AFORM_HPP

#include "Bureaucrat.hpp"
#include "Bureaucrat.hpp"

class	Bureaucrat;
class	AForm
{
	private:
		bool				_signed;
		const std::string	_name;
		const int			_gradeSign;
		const int			_gradeExecute;

	protected:
		class gradeTooLowExpectation : public std::exception
		{
			public:
				const char *what() const throw();
		};

		class gradeTooHighExpectation : public std::exception
		{
			public:
				const char *what() const throw();
		};

	public:
		AForm();
		AForm(const std::string name, const int gradsign, const int gradeExecution);
		AForm(const AForm& object);
		AForm &operator=(AForm const &rhs);
		virtual ~AForm() = 0;

		bool			getSigned() const;
		void			beSigned(Bureaucrat const &rhs);
		std::string		getName() const;
		int				getGradeSign() const;
		int				getGradeExec() const;
		virtual void	execute(Bureaucrat const &excecutor)const = 0;
};

std::ostream &operator<<(std::ostream &out, AForm const &rhs);

#endif
