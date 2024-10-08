/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quvan-de <quvan-de@student.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 16:11:18 by quvan-de          #+#    #+#             */
/*   Updated: 2024/10/07 16:31:19 by quvan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed {
private:
	int	fixedPointValue();
	static const int fractionalBits = 0;
public:
	// Constructors and Destructors
	Fixed();
	Fixed(const int value);
	Fixed(const float value);
	Fixed(const Fixed &other);
	~Fixed();

	// Operator overloads
	Fixed &operator=(const Fixed &other);

	// Comparisson Operators
	bool operator>(const Fixed &other)const;
	bool operator<(const Fixed &other)const;
	bool operator>=(const Fixed &other)const;
	bool operator<=(const Fixed &other)const;
	bool operator==(const Fixed &other)const;
	bool operator!=(const Fixed &other)const;

	// Arthemic Operators
	Fixed operator+(const Fixed &other)const;
	Fixed operator-(const Fixed &other)const;
	Fixed operator*(const Fixed &other)const;
	Fixed operator/(const Fixed &other)const;

	// Increment/Decrement Operators
	Fixed operator++();
	Fixed operator++(int);
	Fixed operator--();
	Fixed operator--(int);

	// Conversion
	float toFloat()const;
	int toInt()const;

	// Min/Max static functions
	static Fixed &min(Fixed &a, Fixed &b);
	static const Fixed &min(const Fixed &a, const Fixed &b);
	static Fixed &max(Fixed &a, Fixed &b);
	static const Fixed &max(const Fixed &q, const Fixed &b);

	// Friend function for << operator overload
	friend std::ostream &operator<<(std::ostream &os, const Fixed &fixed);
};

#endif
