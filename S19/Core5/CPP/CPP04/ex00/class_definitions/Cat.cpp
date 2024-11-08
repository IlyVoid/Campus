/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quvan-de <quvan-de@student.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 03:56:01 by quvan-de          #+#    #+#             */
/*   Updated: 2024/10/29 03:56:01 by quvan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

Cat::Cat(void) : Animal()
{
    std::cout << "Cat Object Created" << std::endl;
    this->type = "Cat";
}

Cat::Cat(const Cat& other) : Animal(other)
{
    std::cout << "Cat Object Copied" << std::endl;
    *this = other;
}

Cat& Cat::operator = (const Cat& other)
{
    std::cout << "Cat Assignment Copied" << std::endl;
    if (this != &other)
        this->type = other.type;
    return (*this);
}

void Cat::makeSound(void) const
{
    std::cout << "Meow" << std::endl;
}

Cat::~Cat(void)
{
    std::cout << "Cat Object Destroyed" << std::endl;
}
