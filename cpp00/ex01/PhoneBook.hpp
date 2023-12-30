/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cafriem <cafriem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 14:39:45 by cafriem           #+#    #+#             */
/*   Updated: 2023/12/27 16:14:17 by cafriem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "contact.hpp"

class	Phonebook
{
	private:
		Contact	contacts[8];
		int		index;
	public:
		Phonebook();
		~Phonebook();

		void	menu();
		void	addcontact();
		void	book();
		void	searchcontact();
		void	texts(int c, int c2);
		int		checker();
};

#endif
