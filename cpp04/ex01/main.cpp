/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhan <mkhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 15:34:23 by mkhan             #+#    #+#             */
/*   Updated: 2023/01/18 21:06:30 by mkhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"

int	main()
{
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
}
