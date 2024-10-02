/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quvan-de <quvan-de@student.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 19:25:22 by quvan-de          #+#    #+#             */
/*   Updated: 2024/10/01 19:25:48 by quvan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./class/PhoneBook.hpp"
#include <iostream>

void addContact(PhoneBook& phoneBook) {
    Contact newContact;
    std::string input;

    std::cout << "Enter First Name: ";
    std::getline(std::cin, input);
    newContact.setFirstName(input);

    std::cout << "Enter Last Name: ";
    std::getline(std::cin, input);
    newContact.setLastName(input);

    std::cout << "Enter Nickname: ";
    std::getline(std::cin, input);
    newContact.setNickname(input);

    std::cout << "Enter Phone Number: ";
    std::getline(std::cin, input);
    newContact.setPhoneNumber(input);

    std::cout << "Enter Darkest Secret: ";
    std::getline(std::cin, input);
    newContact.setDarkestSecret(input);

    phoneBook.addContact(newContact);
}

int main() {
    PhoneBook phoneBook;
    std::string command;

    while (true) {
        std::cout << "Enter command (ADD, SEARCH, EXIT): ";
        std::getline(std::cin, command);

        if (command == "ADD") {
            addContact(phoneBook);
        } else if (command == "SEARCH") {
            phoneBook.displayContacts();
            std::cout << "Enter the index of the contact to display: ";
            int index;
            std::cin >> index;
            std::cin.ignore();
            phoneBook.displayContactDetails(index);
        } else if (command == "EXIT") {
            std::cout << "Exiting..." << std::endl;
            break;
        } else {
            std::cout << "Invalid command!" << std::endl;
        }
    }

    return 0;
}
