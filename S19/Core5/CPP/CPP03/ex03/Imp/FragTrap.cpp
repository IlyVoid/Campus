/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quvan-de <quvan-de@student.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 15:22:56 by quvan-de          #+#    #+#             */
/*   Updated: 2024/10/16 15:23:30 by quvan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Classes/FragTrap.hpp"

// Constructor
FragTrap::FragTrap(const std::string& _name) {
    name = _name;
    hitPoints = 100;
    energyPoints = 100;
    attackDamage = 30;
    std::cout << "FragTrap " << name << " is constructed with "
              << hitPoints << " HP, "
              << energyPoints << " EP, and "
              << attackDamage << " AD." << std::endl;
}

// Destructor
FragTrap::~FragTrap() {
    std::cout << "FragTrap " << name << " is destroyed!" << std::endl;
}

// Attack function override
void FragTrap::attack(const std::string& target) {
    if (hitPoints > 0 && energyPoints > 0) {
        std::cout << "FragTrap " << name << " aggressively attacks " << target
                  << ", dealing " << attackDamage << " points of damage!" << std::endl;
        energyPoints--;
    } else {
        std::cout << "FragTrap " << name << " is either out of energy or dead!" << std::endl;
    }
}

// Special High-Five request
void FragTrap::highFivesGuys(void) {
    std::cout << "FragTrap " << name << " is asking for a high five! ✋" << std::endl;
}
