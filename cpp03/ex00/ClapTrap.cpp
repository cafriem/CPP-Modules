/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cafriem <cafriem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 09:01:58 by cafriem           #+#    #+#             */
/*   Updated: 2024/01/09 20:12:07 by cafriem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	std::cout << "ClapTrap Constructor Called" << std::endl;
}

ClapTrap::ClapTrap(const std::string name)
{
	std::cout << "ClapTrap Constructor Called" << std::endl;
	this->_name = name;
	this->_hit_points = 10;
	this->_energy_points = 10;
	this->_attack_damage = 0;
}

ClapTrap::ClapTrap(const ClapTrap &a)
{
	std::cout << "ClapTrap Copy Constructor Called" << std::endl;
	*this = a;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap Destructor Called" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap &rhs)
{
	std::cout << "ClapTrap Copy Assignment Operator = " << std::endl;
	if (this != &rhs)
	{
		this->_name = rhs._name;
		this->_hit_points = rhs._hit_points;
		this->_energy_points = rhs._energy_points;
		this->_attack_damage = rhs._attack_damage;
	}
	return(*this);
}

void	ClapTrap::attack(const std::string& target)
{
	if (_energy_points > 0 && _hit_points > 0)
	{
		_energy_points--;
		std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing " << this->_attack_damage << " points of damage!" << std::endl;
	}
	else
		std::cout << "ClapTrap " << this->_name << " has no hit points or energy points left to attack" <<  std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (_hit_points > amount)
	{
		_hit_points -= amount;
		std::cout << "Claptrap " << _name << " has taken " << amount << " damage. new hp is" << _hit_points << std::endl;
	}
	else
	{
		_hit_points = 0;
		std::cout << "Claptrap " << _name << " has taken " << amount << " damage and it's hp is 0" << std::endl;
	}
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (_energy_points > 0 && _hit_points > 0)
	{
		_hit_points += amount;
		std::cout << "Claptrap " << _name << " has healed " << amount << ". Hp is now at " << _hit_points << std::endl;
	}
	else
		std::cout << "Claptrap " << _name << " doesn't have enought hitpoints or energy left" << std::endl;
}
