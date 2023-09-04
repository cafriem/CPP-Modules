/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cafriem <cafriem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 14:39:45 by cafriem           #+#    #+#             */
/*   Updated: 2023/09/04 12:20:53 by cafriem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONE_BOOK
# define PHONE_BOOK

class	Phonebook {
	
	pubic:

		Contact person[8];
		Add(void);
};

class	Contact {

	pubic:
		string	FirstName[];
		string	LastName[];
		int		PhoneNumber;
		string	DarkSecret[];

};

#endif
