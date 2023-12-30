/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cafriem <cafriem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 09:01:58 by cafriem           #+#    #+#             */
/*   Updated: 2023/12/29 07:37:37 by cafriem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
	this->_name = name;
}

HumanB::~HumanB()
{}

void	HumanB::attack()
{
	if (_weapon)
		std::cout << _name << " attacks with their " << this->_weapon->getType() << std::endl;
	else
		std::cout << _name << " has no weapon" << std::endl;
}

void	HumanB::setWeapon(Weapon &type)
{
	this->_weapon = &type;
}
