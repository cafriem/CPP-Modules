/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cafriem <cafriem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 09:02:23 by cafriem           #+#    #+#             */
/*   Updated: 2024/01/03 18:37:07 by cafriem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon()
{}

Weapon::Weapon(std::string type): _type(type)
{}

Weapon::~Weapon()
{}

std::string	&Weapon::getType(void)
{
	return(this->_type);
}

void	Weapon::setType(std::string name)
{
	this->_type = name;
}
