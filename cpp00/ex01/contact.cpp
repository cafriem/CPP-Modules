/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cafriem <cafriem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 15:02:21 by cafriem           #+#    #+#             */
/*   Updated: 2023/12/27 15:30:06 by cafriem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "contact.hpp"

Contact::Contact()
{}

Contact::~Contact()
{}

std::string	Contact::get_contactinfo(int flag) const
{
	if (flag == 1)
		return(this->firstname);
	if (flag == 2)
		return(this->lastname);
	if (flag == 3)
		return(this->nickname);
	if (flag == 4)
		return(this->phonenumber);
	if (flag == 5)
		return(this->darksecret);
	return("invalid");
}

int	Contact::setname(std::string text, int flag)
{
	if (text == "")
		return(1);
	for (unsigned long c = 0; c < text.size(); c++)
	{
		if (!isalpha(text[c]))
			return(1);
	}
	// if (text.length() > 10)
	// {
		// text[9] = '.';
		// text.erase(10, text.length() - 10);
	// }
	if (flag == 1)
		this->firstname = text;
	if (flag == 2)
		this->lastname = text;
	if (flag == 3)
		this->nickname = text;
	return(0);
}

int Contact::phonenum(std::string num)
{
	if (num == "")
		return(1);
	for (unsigned int c = 0; c < num.size(); c++)
	{
		if (!isdigit(num[c]))
			return(1);
	}
	// if (num.size() > 10)
	// {
	// 	num[9] = '.';
	// 	num.erase(10, num.size() - 10);
	// }
	this->phonenumber = num;
	return(0);
}	

int Contact::secret(std::string text)
{
	if (text == "")
		return(1);
	// if (text.length() > 10)
	// {
	// 	text[9] = '.';
	// 	text.erase(10, text.length() - 10);
	// }
	this->darksecret = text;
	return(0);
}
