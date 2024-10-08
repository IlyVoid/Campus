/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quvan-de <quvan-de@student.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 19:23:04 by quvan-de          #+#    #+#             */
/*   Updated: 2024/10/08 22:38:22 by quvan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <limits>
#include <algorithm>

class PhoneBook {
private:
    Contact contacts[8];
    int nextIndex;
    int totalContacts;

public:
    PhoneBook();

	int getTotalContacts() const;

    void addContact(const Contact& newContact);
    void displayContacts() const;
    void displayContactDetails(int index) const;
};

#endif
