/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quvan-de <quvan-de@student.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 15:45:25 by quvan-de          #+#    #+#             */
/*   Updated: 2024/10/07 15:45:28 by quvan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {
public:
    Fixed();                                // Default constructor
    Fixed(const int num);                   // Int constructor
    Fixed(const float num);                 // Float constructor
    Fixed(const Fixed &other);              // Copy constructor
    Fixed &operator=(const Fixed &other);   // Copy assignment operator
    ~Fixed();                               // Destructor

    int getRawBits(void) const;
    void setRawBits(int const raw);
    float toFloat(void) const;
    int toInt(void) const;

private:
    int _fixedPointValue;                   // The actual fixed-point value
    static const int _fractionalBits = 8;   // Number of fractional bits
};

// Overloading << operator
std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif
