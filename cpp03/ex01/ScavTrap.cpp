/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cafriem <cafriem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 09:01:58 by cafriem           #+#    #+#             */
/*   Updated: 2024/01/10 01:05:40 by cafriem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	std::cout << "ScavTrap Constructor Called" << std::endl;
}

ScavTrap::ScavTrap(const std::string name) : ClapTrap(name, 100, 50, 20)
{
	std::cout << "ScavTrap Constructor Called" << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const &a)
{
	std::cout << "ScavTrap Copy Constructor Called" << std::endl;
	*this = a;
}

ScavTrap & ScavTrap::operator=(ScavTrap const &rhs)
{
	std::cout << "ScavTrap Copy Assignment Operator = " << std::endl;
	if (this != &rhs)
	{
		this->_name = rhs._name;
		this->_hit_points = rhs._hit_points;
		this->_energy_points = rhs._energy_points;
		this->_attack_damage = rhs._attack_damage;
	}
	return(*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap Destructor Called" << std::endl;
}

void	ScavTrap::attack(const std::string& target)
{
	if (_energy_points > 0 && _hit_points > 0)
	{
		_energy_points--;
		std::cout << "ScavTrap " << this->_name << " attacks " << target << ", causing " << this->_attack_damage << " points of damage!" << std::endl;
	}
	else
		std::cout << "ScavTrap " << this->_name << " has no hit points or energy points left to attack" <<  std::endl;
}

void	ScavTrap::guardGate()
{
	std::cout << "ScavTrap is now in Gate keeper mode." << std::endl;
}
