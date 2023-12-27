/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cafriem <cafriem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 15:02:40 by cafriem           #+#    #+#             */
/*   Updated: 2023/12/27 11:21:51 by cafriem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	CONTACT_HPP
# define CONTACT_HPP

#include <iostream>
#include <string>
#include <cstring>
#include <iomanip>

class	Contact
{
	private:
		std::string	firstname;
		std::string	lastname;
		std::string	nickname;
		std::string	phonenumber;
		std::string	darksecret;

	public:
		Contact();
		~Contact();

		std::string get_contactinfo(int flag) const;
		int	setname(std::string firstname, int flag);
		int phonenum(std::string num);
		int secret(std::string text);
};

#endif