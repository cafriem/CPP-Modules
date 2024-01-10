/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhan <mkhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 13:57:56 by mkhan             #+#    #+#             */
/*   Updated: 2023/01/29 20:04:55 by mkhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>

class Animal
{
	protected:
		std::string _type;
		
	public:
		Animal();
		Animal(Animal const &object);
		Animal &operator=(Animal const &rhs);
		virtual ~Animal();

		virtual void	makeSound() const;
		virtual std::string	getType() const;
};

#endif