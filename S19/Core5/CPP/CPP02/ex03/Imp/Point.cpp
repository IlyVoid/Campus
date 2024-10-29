/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quvan-de <quvan-de@student.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 14:48:40 by quvan-de          #+#    #+#             */
/*   Updated: 2024/10/14 14:56:58 by quvan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Classes/Point.hpp"

// Default constructor
Point::Point() : _x(0), _y(0) {}

// Constructor with float coordinates
Point::Point(const float x, const float y) : _x(Fixed(x)), _y(Fixed(y)) {}

// Copy constructor
Point::Point(const Point &other) : _x(other.getX()), _y(other.getY()) {}

// Destructor
Point::~Point() {}

// Assignment operator
Point &Point::operator=(const Point &other) {
    // No need to copy as _x and _y are const, but we still need the function for compatibility
    (void)other;
    return *this;
}

// Getters for coordinates
Fixed Point::getX() const {
    return this->_x;
}

Fixed Point::getY() const {
    return this->_y;
}
