#include "Contact.hpp"
#include <cstring>
#include <iostream>
#include <string>

Contact::Contact(std::string f_name, std::string l_name, std::string n_name, std::string number, std::string secret){
	this->f_name = f_name;
	this->l_name = l_name;
	this->n_name = n_name;
	this->number = number;
	this->secret = secret;
}

Contact::~Contact(){};

Contact::Contact(){};

std::string Contact::get_string(std::string str) {
	std::string res = "";
	unsigned long	i;

	for(i = 0; i < 9 && i < str.length(); i++)
		res += str[i];
	if (i == 9)
		return (res);
	for (int j = i; j < 10; j++)
		res += ' ';
	return (res);
}

void Contact::print(int index)
{
	std::cout << "┃" << index << "         ";

	std::string f_name = get_string(this->f_name);
	std::cout << "┃" << f_name << (this->f_name.length() > 9 ? "." : "");

	std::string l_name = get_string(this->l_name);
	std::cout << "┃" << l_name << (this->l_name.length() > 9 ? "." : "");

	std::string n_name = get_string(this->n_name);
	std::cout << "┃" << n_name << (this->n_name.length() > 9 ? ".┃" : "┃") << std::endl;
}

void Contact::print_details()
{
	std::cout << "First name: " << this->f_name << std::endl;
	std::cout << "Last name: " << this->l_name << std::endl;
	std::cout << "Nickname: " << this->n_name << std::endl;
	std::cout << "Phone number: " << this->number << std::endl;
	std::cout << "Darkest secret: " << this->secret << std::endl;
}

bool Contact::is_null()
{
	return (this->f_name.empty() && this->l_name.empty() && this->n_name.empty() && this->number.empty() && this->secret.empty());
}
