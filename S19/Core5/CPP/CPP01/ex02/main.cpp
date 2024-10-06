/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quvan-de <quvan-de@student.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 18:00:01 by quvan-de          #+#    #+#             */
/*   Updated: 2024/10/06 18:12:19 by quvan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main()
{
    // Step 1: Initialize the string variable
    std::string brain = "HI THIS IS BRAIN";
    std::cout << "[DEBUG] Initialized string variable 'brain' with value: " << brain << std::endl;

    // Step 2: Create a pointer to the string variable
    std::string* stringPTR = &brain;
    std::cout << "[DEBUG] Pointer 'stringPTR' created, pointing to 'brain'" << std::endl;

    // Step 3: Create a reference to the string variable
    std::string& stringREF = brain;
    std::cout << "[DEBUG] Reference 'stringREF' created, referring to 'brain'" << std::endl;

    // Step 4: Print the memory addresses
    std::cout << "\n[DEBUG] Printing memory addresses..." << std::endl;
    std::cout << "Memory address of the string variable:     " << &brain << std::endl;
    std::cout << "Memory address held by stringPTR:          " << stringPTR << std::endl;
    std::cout << "Memory address held by stringREF:          " << &stringREF << std::endl;

    // Step 5: Print the values
    std::cout << "\n[DEBUG] Printing values..." << std::endl;
    std::cout << "Value of the string variable:              " << brain << std::endl;
    std::cout << "Value pointed to by stringPTR:             " << *stringPTR << std::endl;
    std::cout << "Value referred to by stringREF:            " << stringREF << std::endl;

    std::cout << "[DEBUG] End of program." << std::endl;

    return 0;
}
