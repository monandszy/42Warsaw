#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>
#include <iostream>

class Contact
{
  private:
    int _order;
    std::string _number;
    std::string _firstName;
    std::string _lastName;
    std::string _nickname;
    std::string _darkestSecret;
  
	public:
    std::string getNumber() const;
    std::string getFirstName() const;
    std::string getLastName() const;
    std::string getNickname() const;
    std::string getDarkestSecret() const;
    int getOrder() const;
		Contact(void);
    Contact(std::string _number, int order);
		Contact(const Contact& other);
		Contact &operator=(const Contact &other);
		~Contact();
};

#endif