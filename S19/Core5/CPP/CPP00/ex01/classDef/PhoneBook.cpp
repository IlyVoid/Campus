/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quvan-de <quvan-de@student.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 19:24:32 by quvan-de          #+#    #+#             */
/*   Updated: 2024/10/08 22:46:37 by quvan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../class/PhoneBook.hpp"
#include <iostream>
#include <iomanip>

PhoneBook::PhoneBook() : nextIndex(0), totalContacts(0) {}

void PhoneBook::addContact(const Contact& newContact) {
    contacts[nextIndex] = newContact;
    nextIndex = (nextIndex + 1) % 8;
    if (totalContacts < 8)
        totalContacts++;
}

void PhoneBook::displayContacts() const {
    std::cout << std::setw(10) << "Index" << "|"
              << std::setw(10) << "First Name" << "|"
              << std::setw(10) << "Last Name" << "|"
              << std::setw(10) << "Nickname" << std::endl;
    for (int i = 0; i < totalContacts; ++i) {
        std::cout << std::setw(10) << i + 1 << "|"
                  << std::setw(10) << (contacts[i].getFirstName().length() > 10 ? contacts[i].getFirstName().substr(0, 9) + "." : contacts[i].getFirstName()) << "|"
                  << std::setw(10) << (contacts[i].getLastName().length() > 10 ? contacts[i].getLastName().substr(0, 9) + "." : contacts[i].getLastName()) << "|"
                  << std::setw(10) << (contacts[i].getNickname().length() > 10 ? contacts[i].getNickname().substr(0, 9) + "." : contacts[i].getNickname())
                  << std::endl;
    }
}

int PhoneBook::getTotalContacts() const {
    return totalContacts;
}

void PhoneBook::displayContactDetails(int index) const {
    while (index < 1 || index >= totalContacts) {
        std::cout << "Invalid index!" << std::endl;
    }

    const Contact& contact = contacts[index - 1];
    std::cout << "First Name: " << contact.getFirstName() << std::endl;
    std::cout << "Last Name: " << contact.getLastName() << std::endl;
    std::cout << "Nickname: " << contact.getNickname() << std::endl;
    std::cout << "Phone Number: " << contact.getPhoneNumber() << std::endl;
    std::cout << "Darkest Secret: " << contact.getDarkestSecret() << std::endl;
}
