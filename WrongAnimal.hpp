/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cafriem <cafriem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 11:05:51 by cafriem           #+#    #+#             */
/*   Updated: 2024/01/10 10:34:04 by cafriem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#include <iostream>
#include <string>

class	WrongAnimal
{
	protected:
		std::string	type;

	public:
		WrongAnimal();
		WrongAnimal(WrongAnimal const &a);
		WrongAnimal	&operator=(WrongAnimal const &rhs);
		~WrongAnimal();

		void		makeSound() const;
		std::string getType()const;
};

#endif