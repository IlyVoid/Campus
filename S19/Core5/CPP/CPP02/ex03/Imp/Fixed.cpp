/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quvan-de <quvan-de@student.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 16:11:24 by quvan-de          #+#    #+#             */
/*   Updated: 2024/10/14 14:58:24 by quvan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Classes/Fixed.hpp"

#include "../Classes/Fixed.hpp"

// Default constructor
Fixed::Fixed() : _fixedValue(0) {
    std::cout << "[Constructor] Default constructor called" << std::endl;
}

// Constructor for integer
Fixed::Fixed(const int num) : _fixedValue(num << _fractionalBits) {
    std::cout << "[Constructor] Int constructor called: " << num << std::endl;
}

// Constructor for float
Fixed::Fixed(const float num) : _fixedValue(roundf(num * (1 << _fractionalBits))) {
    std::cout << "[Constructor] Float constructor called: " << num << std::endl;
}

// Copy constructor
Fixed::Fixed(const Fixed &other) {
    std::cout << "[Constructor] Copy constructor called" << std::endl;
    *this = other;
}

// Destructor
Fixed::~Fixed() {
    std::cout << "[Destructor] Destructor called" << std::endl;
}

// Assignment operator
Fixed &Fixed::operator=(const Fixed &other) {
    std::cout << "[Operator=] Assignment operator called" << std::endl;
    if (this != &other) {
        this->_fixedValue = other.getRawBits();
    }
    return *this;
}

// Get and Set functions
int Fixed::getRawBits() const {
    std::cout << "[getRawBits] Called, returning: " << this->_fixedValue << std::endl;
    return this->_fixedValue;
}

void Fixed::setRawBits(int const raw) {
    std::cout << "[setRawBits] Called, setting value to: " << raw << std::endl;
    this->_fixedValue = raw;
}

// Conversion functions
float Fixed::toFloat() const {
    std::cout << "[toFloat] Called, converting to float: " << (float)this->_fixedValue / (1 << _fractionalBits) << std::endl;
    return (float)this->_fixedValue / (1 << _fractionalBits);
}

int Fixed::toInt() const {
    std::cout << "[toInt] Called, converting to int: " << (this->_fixedValue >> _fractionalBits) << std::endl;
    return this->_fixedValue >> _fractionalBits;
}

// Comparison operators
bool Fixed::operator>(const Fixed &other) const {
    std::cout << "[Comparison] Greater-than operator called" << std::endl;
    return this->_fixedValue > other.getRawBits();
}

bool Fixed::operator<(const Fixed &other) const {
    std::cout << "[Comparison] Less-than operator called" << std::endl;
    return this->_fixedValue < other.getRawBits();
}

bool Fixed::operator>=(const Fixed &other) const {
    std::cout << "[Comparison] Greater-than-or-equal operator called" << std::endl;
    return this->_fixedValue >= other.getRawBits();
}

bool Fixed::operator<=(const Fixed &other) const {
    std::cout << "[Comparison] Less-than-or-equal operator called" << std::endl;
    return this->_fixedValue <= other.getRawBits();
}

bool Fixed::operator==(const Fixed &other) const {
    std::cout << "[Comparison] Equality operator called" << std::endl;
    return this->_fixedValue == other.getRawBits();
}

bool Fixed::operator!=(const Fixed &other) const {
    std::cout << "[Comparison] Inequality operator called" << std::endl;
    return this->_fixedValue != other.getRawBits();
}

// Arithmetic operators
Fixed Fixed::operator+(const Fixed &other) const {
    std::cout << "[Arithmetic] Addition operator called" << std::endl;
    Fixed result;
    result.setRawBits(this->_fixedValue + other.getRawBits());
    return result;
}

Fixed Fixed::operator-(const Fixed &other) const {
    std::cout << "[Arithmetic] Subtraction operator called" << std::endl;
    Fixed result;
    result.setRawBits(this->_fixedValue - other.getRawBits());
    return result;
}

Fixed Fixed::operator*(const Fixed &other) const {
    std::cout << "[Arithmetic] Multiplication operator called" << std::endl;
    Fixed result;
    result.setRawBits((this->_fixedValue * other.getRawBits()) >> _fractionalBits);
    return result;
}

Fixed Fixed::operator/(const Fixed &other) const {
    std::cout << "[Arithmetic] Division operator called" << std::endl;
    if (other.getRawBits() == 0) {
        std::cerr << "[Error] Division by zero!" << std::endl;
        exit(1);
    }
    Fixed result;
    result.setRawBits((this->_fixedValue << _fractionalBits) / other.getRawBits());
    return result;
}

// Increment / Decrement operators
Fixed &Fixed::operator++() {
    std::cout << "[Increment] Pre-increment operator called" << std::endl;
    this->_fixedValue++;
    return *this;
}

Fixed Fixed::operator++(int) {
    std::cout << "[Increment] Post-increment operator called" << std::endl;
    Fixed temp = *this;
    this->_fixedValue++;
    return temp;
}

Fixed &Fixed::operator--() {
    std::cout << "[Decrement] Pre-decrement operator called" << std::endl;
    this->_fixedValue--;
    return *this;
}

Fixed Fixed::operator--(int) {
    std::cout << "[Decrement] Post-decrement operator called" << std::endl;
    Fixed temp = *this;
    this->_fixedValue--;
    return temp;
}

// Min / Max functions
Fixed &Fixed::min(Fixed &a, Fixed &b) {
    std::cout << "[Min Function] Non-const version called" << std::endl;
    return (a < b) ? a : b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b) {
    std::cout << "[Min Function] Const version called" << std::endl;
    return (a < b) ? a : b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b) {
    std::cout << "[Max Function] Non-const version called" << std::endl;
    return (a > b) ? a : b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b) {
    std::cout << "[Max Function] Const version called" << std::endl;
    return (a > b) ? a : b;
}

// Output stream overload
std::ostream &operator<<(std::ostream &os, const Fixed &fixed) {
    std::cout << "[Output Stream] << operator called, converting Fixed to float for output" << std::endl;
    os << fixed.toFloat();
    return os;
}
