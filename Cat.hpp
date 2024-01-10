/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cafriem <cafriem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 11:05:51 by cafriem           #+#    #+#             */
/*   Updated: 2024/01/08 03:46:40 by cafriem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#include "Animal.hpp"

class	Cat : public Animal
{
	protected:
		std::string type;

	public:
		Cat();
		Cat(Cat const &a);
		Cat	&operator=(Cat const &rhs);
		~Cat();

		void		makeSound() const;
		std::string getType()const;
};

#endif
