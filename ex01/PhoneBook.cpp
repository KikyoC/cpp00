#include "PhoneBook.hpp"
#include <cctype>
#include <cstdlib>
#include <iostream>
#include <limits>
#include <ostream>
#include <string>

PhoneBook::PhoneBook(void){
	this->last_id = -1;
}

void PhoneBook::add_contact(Contact contact)
{
	this->last_id ++;
	if (this->last_id >= 8)
		this->last_id = 0;
	this->contacts[this->last_id] = contact;
}

void print_separation_line()
{
	std::cout << "┣━━━━━━━━━━╋━━━━━━━━━━╋━━━━━━━━━━╋━━━━━━━━━━┫" << std::endl;
}

void PhoneBook::print_book()
{
	std::cout << "┏━━━━━━━━━━┳━━━━━━━━━━┳━━━━━━━━━━┳━━━━━━━━━━┓" << std::endl << "┃INDEX     ┃FIRSTNAME ┃LASTNAME  ┃NICKNAME  ┃" << std::endl;
	print_separation_line();
	for (int i = 0; i < 8; i++)
	{
		this->contacts[i].print(i);
		if (i < 7)
			print_separation_line();
	}
	std::cout << "┗━━━━━━━━━━┻━━━━━━━━━━┻━━━━━━━━━━┻━━━━━━━━━━┛" << std::endl;
}

int force_ask(std::string question, std::string *res)
{
	std::cout << question << std::endl;
	if (!std::getline(std::cin, *res))
	{
		std::cout << "exit" << std::endl;
		return(1);
	}
	return (0);
}

int add_contact_prompt(PhoneBook *pb)
{
	std::string f_name;
	std::string l_name;
	std::string n_name;
	std::string number;
	std::string secret;

	if (force_ask("What's the first name ?", &f_name)
		|| force_ask("What's the last name ?", &l_name)
		|| force_ask("What's the nickname ?", &n_name)
		|| force_ask("What's the number of " + f_name + "?", &number)
		|| force_ask("What's his/her darkest secret ?", &secret))
		return (1);
	Contact contact(f_name, l_name, n_name, number, secret);
	pb->add_contact(contact);
	std::cout << "Added new contact " << f_name << std::endl;
	return (0);
}

Contact *PhoneBook::get_contacts()
{
	return (this->contacts);
}

int search_contact(PhoneBook pb)
{
	int id;
	pb.print_book();
	std::string str_id;
	if (force_ask("Which account do you want to see ? (Type the contact id)", &str_id))
		return (1);
	for (int i = 0; str_id[i]; i++)
	{
		if (!isdigit(str_id[i]))
		{
			std::cout << "This is not an integer!" << std::endl;
			return (0);
		}
	}
	id = std::stoi(str_id);
	if (id > 7)
	{
		std::cout << "This is not a valid integer (Can only be between 0 and 7 inclued)" << std::endl;
		return (0);
	}
	Contact contact = pb.get_contacts()[id];
	if (contact.is_null())
	{
		std::cout << "This contact has not been set" << std::endl;
		return (0);
	}
	contact.print_details();
	return (0);
}

int main(void)
{
	PhoneBook pb;
	std::string answer;

	while (!force_ask("Available commands: ADD SEARCH EXIT", &answer) && answer.compare("EXIT"))
	{
		if (!answer.compare("ADD") && add_contact_prompt(&pb))
				return (1) ;
		else if (!answer.compare("SEARCH"))
			search_contact(pb);
	}
}

