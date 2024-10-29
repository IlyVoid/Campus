/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quvan-de <quvan-de@student.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 14:49:47 by quvan-de          #+#    #+#             */
/*   Updated: 2024/10/14 14:59:29 by quvan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Classes/Point.hpp"

// Function to compute the sign of the area (helper for BSP)
static Fixed sign(const Point &p1, const Point &p2, const Point &p3) {
    return (p1.getX() - p3.getX()) * (p2.getY() - p3.getY()) - (p2.getX() - p3.getX()) * (p1.getY() - p3.getY());
}

// Function to check if a point is inside a triangle
bool bsp(const Point &a, const Point &b, const Point &c, const Point &point) {
    Fixed d1, d2, d3;
    bool has_neg, has_pos;

    // Calculate the signs of the areas of the sub-triangles
    d1 = sign(point, a, b);
    d2 = sign(point, b, c);
    d3 = sign(point, c, a);

    // Check if all the signs are consistent (either all positive or all negative)
    has_neg = (d1 < Fixed(0)) || (d2 < Fixed(0)) || (d3 < Fixed(0));
    has_pos = (d1 > Fixed(0)) || (d2 > Fixed(0)) || (d3 > Fixed(0));

    return !(has_neg && has_pos);  // Inside if all signs are consistent
}
