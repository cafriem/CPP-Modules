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

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"

class	ShrubberyCreationForm : public AForm
{
	private:
		std::string	_target;
		void		_asciiTree() const;
		class	fileError : public std::exception
		{
			public:
				const char *what() const throw();
		};

	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string _target);
		ShrubberyCreationForm(ShrubberyCreationForm const &object);
		ShrubberyCreationForm &operator=(const ShrubberyCreationForm &rhs);
		~ShrubberyCreationForm();

		void		execute(Bureaucrat const &executor) const;
		std::string	getTarget() const;
};

#endif
