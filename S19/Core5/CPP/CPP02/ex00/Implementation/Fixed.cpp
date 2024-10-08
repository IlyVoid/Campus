/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quvan-de <quvan-de@student.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 12:50:46 by quvan-de          #+#    #+#             */
/*   Updated: 2024/10/07 12:54:11 by quvan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Classes/Fixed.hpp"

// Default constructor
Fixed::Fixed() : _fixedPointValue(0) {
    std::cout << "[DEBUG] Default constructor called" << std::endl;
    std::cout << "[DEBUG] _fixedPointValue initialized to " << _fixedPointValue << std::endl;
}

// Copy constructor
Fixed::Fixed(const Fixed& other) {
    std::cout << "[DEBUG] Copy constructor called" << std::endl;
    *this = other; // Use assignment operator to copy values.
    std::cout << "[DEBUG] _fixedPointValue copied from other object: " << this->_fixedPointValue << std::endl;
}

// Destructor
Fixed::~Fixed() {
    std::cout << "[DEBUG] Destructor called" << std::endl;
}

// Assignment operator overload
Fixed& Fixed::operator=(const Fixed& other) {
    std::cout << "[DEBUG] Copy assignment operator called" << std::endl;
    if (this != &other) { // Self-assignment check.
        std::cout << "[DEBUG] Assigning _fixedPointValue from " << this->_fixedPointValue << " to " << other.getRawBits() << std::endl;
        this->_fixedPointValue = other.getRawBits();
    } else {
        std::cout << "[DEBUG] Self-assignment detected. No action taken." << std::endl;
    }
    return *this;
}

// Get the raw value of the fixed-point number
int Fixed::getRawBits(void) const {
    std::cout << "[DEBUG] getRawBits member function called" << std::endl;
    std::cout << "[DEBUG] Returning _fixedPointValue: " << this->_fixedPointValue << std::endl;
    return this->_fixedPointValue;
}

// Set the raw value of the fixed-point number
void Fixed::setRawBits(int const raw) {
    std::cout << "[DEBUG] setRawBits member function called" << std::endl;
    std::cout << "[DEBUG] Setting _fixedPointValue from " << this->_fixedPointValue << " to " << raw << std::endl;
    this->_fixedPointValue = raw;
}
