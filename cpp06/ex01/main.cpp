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

#include "Serialize.hpp"

int	main()
{
	Data data;
	data.data = "Testing";
	data.c = 42;

	uintptr_t serializedValue = Serialize::serialize(&data);
	std::cout << "serializedValue  : " << serializedValue << std::endl;
	
	Data *deserializedValue = Serialize::deserialize(serializedValue);

	std::cout << "-----------------------------------------------" << std::endl;
	std::cout << "&data            : " << &data << std::endl;
	std::cout << "deserializeValue : " << deserializedValue << std::endl;
	std::cout << deserializedValue->c << " + " << deserializedValue->data << std::endl;
	return (0);
}
