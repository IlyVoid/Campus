/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quvan-de <quvan-de@student.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 03:56:01 by quvan-de          #+#    #+#             */
/*   Updated: 2024/10/29 03:56:01 by quvan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

Dog::Dog(void) : Animal()
{
    std::cout << "Dog Object Created" << std::endl;
    this->type = "Dog";
}

Dog::Dog(const Dog& other) : Animal(other)
{
    std::cout << "Dog Object Copied" << std::endl;
    *this = other;
}

Dog& Dog::operator = (const Dog& other)
{
    std::cout << "Dog Assignment Copied" << std::endl;
    if (this != &other)
        this->type = other.type;
    return (*this);
}

void Dog::makeSound(void) const
{
    std::cout << "Woef" << std::endl;
}

Dog::~Dog(void)
{
    std::cout << "Dog Object Destroyed" << std::endl;
}
