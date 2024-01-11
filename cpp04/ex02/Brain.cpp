/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cafriem <cafriem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 09:01:58 by cafriem           #+#    #+#             */
/*   Updated: 2024/01/11 13:51:45 by cafriem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain Constructor Called" << std::endl;
	for (int i = 0; i < 100; i++)
		this->ideas[i] = "Idea" + std::to_string(i);
	
}

Brain::Brain(Brain const &a)
{
	std::cout << "Brain Copy Constructor Called" << std::endl;
	*this = a;
}

Brain& Brain::operator=(Brain const &rhs)
{
	std::cout << "Brain Copy Assignment Operator = " << std::endl;
	if (this != &rhs)
	{
		for (int i = 0; i < 100; i++)
			this->ideas[i] = rhs.ideas[i];
	}
	return(*this);
}

Brain::~Brain()
{
	std::cout << "Brain Destructor Called" << std::endl;
}

void	Brain::getIdeas() const
{
	for (int i = 0; i < 100; i++)
		std::cout << this->ideas[i] << std::endl;
}

void	Brain::setIdeas(std::string *ideas)
{
	for (int i = 0; i < 100; i++)
		this->ideas[i] = ideas[i];
}

void	Brain::changeIdeas()
{
	for (int i = 0; i < 100; i++)
		this->ideas[i] = "a better idea";
}

std::string	*Brain::getIdeas()
{
	return(this->ideas);
}
