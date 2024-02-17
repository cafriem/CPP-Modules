/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cafriem <cafriem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 17:39:03 by cafriem           #+#    #+#             */
/*   Updated: 2024/01/11 17:39:03 by cafriem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"

int	main()
{
	Cat i;
	std::cout << i.getBrain()->getIdeas()[0] << "\n";
	std::cout << "***************************************" << std::endl;
	Animal* animals[10];
	for (int i = 0; i < 10; i++)
	{
		if (i > 5)
			animals[i] = new Cat();
		if (i <= 5)
			animals[i] = new Dog();
	}
	for (int i = 0; i < 10; i++)
		delete animals[i];
	
	// Animal Cat;
}
