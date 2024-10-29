/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quvan-de <quvan-de@student.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 14:50:40 by quvan-de          #+#    #+#             */
/*   Updated: 2024/10/14 15:05:01 by quvan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Classes/Point.hpp"
#include <iostream>

int main() {
    Point a(0.0f, 0.0f);
    Point b(10.0f, 0.0f);
    Point c(0.0f, 10.0f);
    Point point(5.0f, 5.0f);

    if (bsp(a, b, c, point)) {
        std::cout << "Point is inside the triangle" << std::endl;
    } else {
        std::cout << "Point is outside the triangle" << std::endl;
    }

    return 0;
}
