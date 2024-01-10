/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhan <mkhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 14:42:40 by mkhan             #+#    #+#             */
/*   Updated: 2023/01/29 20:04:55 by mkhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>
#include <string>

class WrongAnimal
{
	protected:
		std::string _type;
		
	public:
		WrongAnimal();
		WrongAnimal(WrongAnimal const &object);
		WrongAnimal &operator=(WrongAnimal const &rhs);
		~WrongAnimal();

		void	makeSound() const;
		std::string	getType() const;
};

#endif