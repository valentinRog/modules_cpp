#include "PhoneBook.hpp"

int main() {
  PhoneBook phoneBook;
  phoneBook.add_contact(Contact("sa", "af", "af", "fa"));
  phoneBook.add_contact(Contact("sasafamabdsfadsfjkadsjfnabdsfjkf", "af", "af", "fa"));
  phoneBook.add_contact(Contact("sa", "af", "af", "fa"));
  phoneBook.add_contact(Contact("sa", "af", "af", "fa"));
  phoneBook.print_contacts();
  return 0;
}