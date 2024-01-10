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

#ifndef	BRAIN_HPP
# define BRAIN_HPP

#include <iostream>
#include <cstdlib>
#include <string>

class	Brain
{
	public:
		std::string ideas[100];

		Brain();
		Brain(Brain const &a);
		Brain &operator=(Brain const &rhs);
		~Brain();

		void		getIdeas()const;
		void		setIdeas(std::string *ideas);
		std::string	*getIdeas();
		void		changeIdeas();
};

#endif
