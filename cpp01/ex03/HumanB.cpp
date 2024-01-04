/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cafriem <cafriem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 09:02:23 by cafriem           #+#    #+#             */
/*   Updated: 2024/01/04 11:57:56 by cafriem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
	this->_name = name;
	this->_weapon = NULL;
}

HumanB::~HumanB()
{}

void	HumanB::attack()
{
	std::cout << this->_name << " attacks with "<< this->_weapon->getType() << std::endl;
}

void	HumanB::setWeapon(Weapon &type)
{
	this->_weapon = &type;
}
