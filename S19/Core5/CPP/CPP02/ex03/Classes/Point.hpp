/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quvan-de <quvan-de@student.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 14:47:58 by quvan-de          #+#    #+#             */
/*   Updated: 2024/10/14 15:03:35 by quvan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP

#include "./Fixed.hpp"

class Point {
private:
    const Fixed _x;
    const Fixed _y;

public:
    Point();                           // Default constructor
    Point(const float x, const float y); // Constructor with float coordinates
    Point(const Point &other);          // Copy constructor
    ~Point();                          // Destructor

    Point &operator=(const Point &other); // Assignment operator

    // Getters for coordinates
    Fixed getX() const;
    Fixed getY() const;
};

bool bsp(const Point &a, const Point &b, const Point &c, const Point &point);

#endif
