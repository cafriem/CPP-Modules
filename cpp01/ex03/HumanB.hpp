/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cafriem <cafriem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 11:05:51 by cafriem           #+#    #+#             */
/*   Updated: 2023/12/29 06:35:58 by cafriem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	HUMANB_HPP
# define HUMANB_HPP

#include "Weapon.hpp"

class	HumanB
{
	private:
		Weapon		*_weapon;
		std::string	_name;

	public:
		HumanB(std::string name);
		~HumanB();

		void	attack();
		void	setWeapon(Weapon &type);
};

#endif
