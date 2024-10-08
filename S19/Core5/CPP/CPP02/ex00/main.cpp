/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quvan-de <quvan-de@student.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 12:52:40 by quvan-de          #+#    #+#             */
/*   Updated: 2024/10/07 12:54:28 by quvan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Classes/Fixed.hpp"

int main(void) {
    std::cout << "[DEBUG] Creating Fixed a" << std::endl;
    Fixed a;

    std::cout << "[DEBUG] Creating Fixed b (copy of a)" << std::endl;
    Fixed b(a); // Copy constructor

    std::cout << "[DEBUG] Creating Fixed c" << std::endl;
    Fixed c;

    std::cout << "[DEBUG] Assigning b to c" << std::endl;
    c = b; // Assignment operator

    std::cout << "[DEBUG] Getting raw bits from a" << std::endl;
    std::cout << a.getRawBits() << std::endl;

    std::cout << "[DEBUG] Getting raw bits from b" << std::endl;
    std::cout << b.getRawBits() << std::endl;

    std::cout << "[DEBUG] Getting raw bits from c" << std::endl;
    std::cout << c.getRawBits() << std::endl;

    return 0;
}
