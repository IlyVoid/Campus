/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quvan-de <quvan-de@student.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 18:43:38 by quvan-de          #+#    #+#             */
/*   Updated: 2024/10/06 19:04:54 by quvan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Classes/HumanB.hpp"

HumanB::HumanB(std::string name) : name(name), weapon(NULL) {
    std::cout << "[DEBUG] HumanB " << this->name << " created without weapon" << std::endl;
}

void HumanB::setWeapon(Weapon& weapon) {
    this->weapon = &weapon;
    std::cout << "[DEBUG] HumanB " << this->name << " is now armed with weapon: " << this->weapon->getType() << std::endl;
}

void HumanB::attack() const
{
    if (this->weapon)
        std::cout << RED << this->name << RESET << " attacks with their " 
                  << BLUE << this->weapon->getType() << RESET << std::endl;
    else
        std::cout << RED << this->name << RESET << " is unarmed!" << std::endl;
}

HumanB::~HumanB() {
    std::cout << "[DEBUG] HumanB " << this->name << " destroyed" << std::endl;
}
