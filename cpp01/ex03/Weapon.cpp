/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cafriem <cafriem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 09:01:58 by cafriem           #+#    #+#             */
/*   Updated: 2023/12/29 07:36:46 by cafriem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon()
{}

Weapon::Weapon(std::string type)
{
	this->_type = type;
}

Weapon::~Weapon()
{}

std::string	&Weapon::getType()
{
	return(this->_type);
}

void	Weapon::setType(std::string type)
{
	this->_type = type;
}
