/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quvan-de <quvan-de@student.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 23:23:17 by quvan-de          #+#    #+#             */
/*   Updated: 2024/09/30 23:26:55 by quvan-de         ###   ########.fr       */
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
	std:: string darkestSectret;

public:
	//setters
	void setFirstName(std:: string firstName);
	void setLastName(std:: string lastName);
}
