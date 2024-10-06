/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quvan-de <quvan-de@student.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 00:12:41 by quvan-de          #+#    #+#             */
/*   Updated: 2024/10/06 17:46:39 by quvan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Classes/zombie.hpp"


Zombie::Zombie(std::string name)
{
    this->z_name = name;
    std::cout << "Zombie " << this->z_name << ": Spawned" << std::endl;
}

Zombie::Zombie(void)
{
    this->z_name = "Uninitialised";
    std::cout << "Zombie " << this->z_name << ": Spawned" << std::endl;
}

Zombie::~Zombie(void)
{
    std::cout << this->z_name << ": Died by an accidental explosion..." << std::endl;
}

void    Zombie::announce(void)
{
    std::cout << this->z_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void    Zombie::setName(std::string name)
{
    std::cout << "Changed " << this->z_name;
    this->z_name = name;
    std::cout << " To " << this->z_name << std::endl;
}
