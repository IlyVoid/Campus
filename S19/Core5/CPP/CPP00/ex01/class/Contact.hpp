/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quvan-de <quvan-de@student.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 23:23:17 by quvan-de          #+#    #+#             */
/*   Updated: 2024/10/01 19:08:38 by quvan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <string>

class Contact {
private:
	std:: string firstName;
	std:: string lastName;
	std:: string nickname;
	std:: string phoneNumber;
	std:: string darkestSecret;

public:
	//setters
	void setFirstName(std:: string firstName);
	void setLastName(std:: string lastName);
	void setNickname(std:: string nickname);
	void setPhoneNumber(std:: string phoneNumber);
	void setDarkestSecret(std:: string darkestSecret);

	//getters
	std::string getFirstName() const;
	std::string getLastName() const;
	std::string getNickname() const;
	std::string getPhoneNumber() const;
	std::string getDarkestSecret() const;
};

#endif
