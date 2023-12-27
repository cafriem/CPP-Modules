/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cafriem <cafriem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 15:03:11 by cafriem           #+#    #+#             */
/*   Updated: 2023/12/27 10:18:25 by cafriem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

Phonebook::Phonebook()
{
	this->index = 0;
	std::cout << "Phonebook Constructor" << std::endl;
}

Phonebook::~Phonebook()
{
	std::cout << "Phonebook deconstructor" << std::endl;
}

void	helpmenu(void)
{
	std::cout<< "---Commands---" << std::endl;
	std::cout<< "add" << std::endl;
	std::cout<< "search" << std::endl;
	std::cout<< "exit" << std::endl;
}

void	Phonebook::addcontact()
{
	std::string	firstname = "";
	std::string	lastname = "";
	std::string	nickname = "";
	std::string	phonenumber = "";
	std::string	darksecret = "";
	int	flag = 0;

	while((std::cin.good() && firstname.empty()) || flag == 1)
	{
		flag = 0;
		std::cout << "Firstname : ";
		getline(std::cin, firstname);
		if(firstname.empty())
			std::cout << "Invalid input : empty string" << std::endl;
		if(contacts[index % 8].setname(firstname, 1) == 1)
		{
			flag = 1;
			std::cout << "Invalid name" << std::endl;
		}
	}
	while((std::cin.good() && lastname.empty()) || flag == 1)
	{
		flag = 0;
		std::cout << "lastname : ";
		getline(std::cin, lastname);
		if(lastname.empty())
			std::cout << "Invalid input : empty string" << std::endl;
		if(contacts[index % 8].setname(lastname, 2) == 1)
		{
			flag = 1;
			std::cout << "Invalid name" << std::endl;
		}
	}
	while((std::cin.good() && nickname.empty()) || flag == 1)
	{
		flag = 0;
		std::cout << "nickname : ";
		getline(std::cin, nickname);
		if(nickname.empty())
			std::cout << "Invalid input : empty string" << std::endl;
		if(contacts[index % 8].setname(nickname, 3) == 1)
		{
			flag = 1;
			std::cout << "Invalid name" << std::endl;
		}
	}
	while((std::cin.good() && phonenumber.empty()) || flag == 1)
	{
		flag = 0;
		std::cout << "phonenumber : ";
		getline(std::cin, phonenumber);
		if(phonenumber.empty())
			std::cout << "Invalid input : empty number" << std::endl;
		if(contacts[index % 8].phonenum(phonenumber) == 1)
		{
			flag = 1;
			std::cout << "Invalid number" << std::endl;
		}
	}
	while((std::cin.good() && darksecret.empty()) || flag == 1)
	{
		flag = 0;
		std::cout << "Dark Secret : ";
		getline(std::cin, darksecret);
		if(darksecret.empty())
		{
			flag = 1;
			std::cout << "Invalid input : emptry string" << std::endl;
		}
		contacts[index % 8].secret(darksecret);
	}
	this->index++;
}

void	Phonebook::searchcontact()
{
	book();
	int	search = 0;
	std::string num;
	std::cout << "Index of contact :";
	std::cin >> num;
	search = atoi(num.c_str());
	if(std::cin.fail() || num.size() > 1 || search < 0 || search > 7 || search > (index - 1))
		std::cout << "Invalid input" << std::endl;
	else
	{
		std::cout << "First name: " << contacts[search].get_contactinfo(1) << std::endl;
		std::cout << "Last name: " << contacts[search].get_contactinfo(2) << std::endl;
		std::cout << "Nickname: " << contacts[search].get_contactinfo(3) << std::endl;
		std::cout << "Phonenumber: " << contacts[search].get_contactinfo(4) << std::endl;
		std::cout << "Darksecret: " << contacts[search].get_contactinfo(5) << std::endl;
	}
	std::cin.ignore(num.size(), '\n');
}

void	Phonebook::book()
{
	std::cout << " --Contacts-- \n";
	std::cout << "|  index   |firstname | lastname | nickname |\n";
	for (int c = 0; c < 8; c++)
	{
		std::cout << "|" << std::setw(10) << c;
		std::cout << "|" << std::setw(10) << contacts[c].get_contactinfo(1);
		std::cout << "|" << std::setw(10) << contacts[c].get_contactinfo(2);
		std::cout << "|" << std::setw(10) << contacts[c].get_contactinfo(3);
		std::cout << "|" << std::endl;
	}
	std::cout << " ----------------------" << std::endl;
}

void	Phonebook::menu()
{
	std::cout << "---PhoneBook function Menu---" << std::endl;
	std::cout << "|             add           |" << std::endl;
	std::cout << "|             search        |" << std::endl;
	std::cout << "|             help          |" << std::endl;
	std::cout << "|             exit          |" << std::endl;
	std::cout << "-----------------------------" << std::endl;
}

int	main(void)
{
	Phonebook phonebook;
	phonebook.menu();
	std::cout<< "> ";
	std::string	input;
	while(getline(std::cin, input))
	{
		if(input.compare("add") == 0)
			phonebook.addcontact();
		else if(input.compare("search") == 0)
			phonebook.searchcontact();
		else if(input.compare("exit") == 0)
			break;
		else
		{
			std::cout << "Enter a valid function from the menu" << std::endl;
			phonebook.menu();
		}
		std::cout << "> ";
	}
	return(0);
}
