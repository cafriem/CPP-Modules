/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cafriem <cafriem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 15:03:11 by cafriem           #+#    #+#             */
/*   Updated: 2023/12/29 06:10:26 by cafriem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

Phonebook::Phonebook()
{
	this->index = 0;
}

Phonebook::~Phonebook()
{}

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
	int	bigflag = 0;
	int	flag = 0;

	while(bigflag == 0 && ((firstname.empty()) || flag == 1))
	{
		flag = 0;
		std::cout << "Firstname : ";
		if (!getline(std::cin, firstname))
		{
			bigflag = 1;
			break;
		}
		if(firstname.empty())
			std::cout << "Invalid input : empty string" << std::endl;
		if(contacts[index % 8].setname(firstname, 1) == 1)
		{
			flag = 1;
			std::cout << "Invalid name" << std::endl;
		}
	}
	while(bigflag == 0 && ((lastname.empty()) || flag == 1))
	{
		flag = 0;
		std::cout << "lastname : ";
		if (!getline(std::cin, lastname))
		{
			bigflag = 1;
			break;
		}
		if(lastname.empty())
			std::cout << "Invalid input : empty string" << std::endl;
		if(contacts[index % 8].setname(lastname, 2) == 1)
		{
			flag = 1;
			std::cout << "Invalid name" << std::endl;
		}
	}
	while(bigflag == 0 && ((nickname.empty()) || flag == 1))
	{
		flag = 0;
		std::cout << "nickname : ";
		if (!getline(std::cin, nickname))
		{
			bigflag = 1;
			break;
		}
		if(nickname.empty())
			std::cout << "Invalid input : empty string" << std::endl;
		if(contacts[index % 8].setname(nickname, 3) == 1)
		{
			flag = 1;
			std::cout << "Invalid name" << std::endl;
		}
	}
	while(bigflag == 0 && ((phonenumber.empty()) || flag == 1))
	{
		flag = 0;
		std::cout << "phonenumber : ";
		if (!getline(std::cin, phonenumber))
		{
			bigflag = 1;
			break;
		}
		if(phonenumber.empty())
			std::cout << "Invalid input : empty number" << std::endl;
		if(contacts[index % 8].phonenum(phonenumber) == 1)
		{
			flag = 1;
			std::cout << "Invalid number" << std::endl;
		}
	}
	while(bigflag == 0 && ((darksecret.empty()) || flag == 1))
	{
		flag = 0;
		std::cout << "Dark Secret : ";
		if (!getline(std::cin, darksecret))
		{
			bigflag = 1;
			break;
		}
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

void	Phonebook::texts(int c, int c2)
{
	std::string text = contacts[c].get_contactinfo(c2);
	if (text.length() > 10)
	{
		text[9] = '.';
		text.erase(10, text.length() - 10);
	}
	std::cout << "|" << std::setw(10) << text;
}

void	Phonebook::book()
{
	std::cout << " --Contacts-- \n";
	std::cout << "|  index   |firstname | lastname | nickname |\n";
	for (int c = 0; c < 8; c++)
	{
		std::cout << "|" << std::setw(10) << c;
		texts(c, 1);
		texts(c, 2);
		texts(c, 3);
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

int	Phonebook::checker()
{
	if (contacts[(index - 1) % 8].get_contactinfo(1).empty() || contacts[(index - 1) % 8].get_contactinfo(2).empty()
		|| contacts[(index - 1) % 8].get_contactinfo(3).empty() || contacts[(index - 1) % 8].get_contactinfo(4).empty()
		|| contacts[(index - 1) % 8].get_contactinfo(5).empty())
		return(1);
	return(0);
}

int	main(void)
{
	Phonebook phonebook;
	phonebook.menu();
	std::cout<< "> ";
	std::string	input;
	while(1)
	{
		if (!getline(std::cin, input))
			return(0);
		if(input.compare("add") == 0)
		{
			phonebook.addcontact();
			if (phonebook.checker() == 1)
				break;
		}
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
