/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quvan-de <quvan-de@student.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 18:40:00 by quvan-de          #+#    #+#             */
/*   Updated: 2024/10/06 19:04:33 by quvan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Classes/HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& weapon) : name(name), weapon(weapon) {
    std::cout << "[DEBUG] HumanA " << this->name << " created with weapon: " << this->weapon.getType() << std::endl;
}

void HumanA::attack() const
{
    std::cout << GREEN << this->name << RESET << " attacks with their " 
              << CYAN << this->weapon.getType() << RESET << std::endl;
}

HumanA::~HumanA() {
    std::cout << "[DEBUG] HumanA " << this->name << " destroyed" << std::endl;
}
