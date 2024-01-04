/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cafriem <cafriem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 09:02:23 by cafriem           #+#    #+#             */
/*   Updated: 2024/01/03 19:07:05 by cafriem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &type): _weapon(type)
{
	this->_name = name;
}

HumanA::~HumanA()
{}

void	HumanA::attack()
{
	std::cout << this->_name << " attacks with "<< this->_weapon.getType() << std::endl;
}
