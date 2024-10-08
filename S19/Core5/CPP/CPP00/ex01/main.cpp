/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quvan-de <quvan-de@student.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 19:25:22 by quvan-de          #+#    #+#             */
/*   Updated: 2024/10/08 22:50:50 by quvan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./class/PhoneBook.hpp"
#include <iostream>

void addContact(PhoneBook& phoneBook) {
    Contact newContact;
    std::string input;

    std::cout << "Enter First Name: ";
	std::getline(std::cin, input);
	if (std::cin.eof())
		return exit(9), void();
	while (input == "\0") {
		std::cout << "Enter a valid first name: ";
		std::getline(std::cin, input);
	}
	newContact.setFirstName(input);

    std::cout << "Enter Last Name: ";
    std::getline(std::cin, input);
	if (std::cin.eof())
		return exit(9), void();
	while (input == "\0") {
		std::cout << "Enter a valid last name: ";
		std::getline(std::cin, input);
	}
    newContact.setLastName(input);

    std::cout << "Enter Nickname: ";
    std::getline(std::cin, input);
	if (std::cin.eof())
		return exit(9), void();
	while (input == "\0") {
		std::cout << "Enter a valid nickname: ";
		std::getline(std::cin, input);
	}
    newContact.setNickname(input);

    std::cout << "Enter Phone Number: ";
    std::getline(std::cin, input);
	if (std::cin.eof())
		return exit(9), void();
	while (input == "\0") {
		std::cout << "Enter a valid phone number: ";
		std::getline(std::cin, input);
	}
    newContact.setPhoneNumber(input);

    std::cout << "Enter Darkest Secret: ";
    std::getline(std::cin, input);
	if (std::cin.eof())
		return exit(9), void();
	while (input == "\0") {
		std::cout << "Enter a valid darkest secret: ";
		std::getline(std::cin, input);
	}
    newContact.setDarkestSecret(input);

    phoneBook.addContact(newContact);
}

int main() {
    PhoneBook phoneBook;
    std::string command;

    while (true) {
        std::cout << "Enter command (ADD, SEARCH, EXIT): ";
        std::getline(std::cin, command);

		if (std::cin.eof())
			return 1;
        if (command == "ADD") {
            addContact(phoneBook);
        } else if (command == "SEARCH") {
			phoneBook.displayContacts();
			std::cout << "Enter the index of the contact to display: ";
			int index;
			std::cin >> index;
			if (std::cin.fail() || index < 1 || index > phoneBook.getTotalContacts()) {
				std::cout << "Invalid input!" << std::endl;
				std::cin.clear();  // clear the error flag
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			} else {
				phoneBook.displayContactDetails(index);
			}
        } else if (command == "EXIT") {
            std::cout << "Exiting..." << std::endl;
            break;
        } else {
            std::cout << "Invalid command!" << std::endl;
        }
    }
    return 0;
}
