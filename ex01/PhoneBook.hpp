#ifndef __PHONEBOOK_H__
#define __PHONEBOOK_H__



#include "Contact.hpp"

class PhoneBook {
	public:
		PhoneBook(void);
		void add_contact(Contact contact);
		void print_book();
		Contact *get_contacts();
	private:
		Contact contacts[9];
		int	last_id;
};
#endif
