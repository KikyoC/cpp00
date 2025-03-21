
#ifndef __CONTACT_H__
#define __CONTACT_H__

#include <string>
class Contact {
	public:
		Contact(std::string f_name, std::string l_name, std::string n_name, std::string number, std::string secret);
		Contact();
		~Contact();
		void print(int index);
		void print_details();
		bool is_null();

	private:
		std::string f_name;
		std::string l_name;
		std::string n_name;
		std::string number;
		std::string secret;
		std::string get_string(std::string);
};
#endif
