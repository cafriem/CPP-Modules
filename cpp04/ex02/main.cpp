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
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	delete j;//should not create a leak
	delete i;

	return 0;
}

// int	main()
// {
// 	const Animal* j = new Dog();
// 	const Animal* i = new Cat();
// 	delete j;//should not create a leak
// 	delete i;

// 	int size = 10;
// 	Animal* animals[size];
// 	Animal bla;
// 	for (int i = 0; i < size + 1; i++)
// 	{
// 		if (i % 2 == 0)
// 			animals[i] = new Dog();
// 		else
// 			animals[i] = new Cat();
// 	}
// 	for (int i = size; i > -1; i--)
// 		delete animals[i];

// 	Dog tmp;
// 	{
// 		Dog basic = tmp;
// 	}
// }