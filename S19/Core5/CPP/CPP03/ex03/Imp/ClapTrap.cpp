/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quvan-de <quvan-de@student.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 12:26:07 by quvan-de          #+#    #+#             */
/*   Updated: 2024/10/16 15:17:38 by quvan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Classes/ClapTrap.hpp"

// Default constructor for derived classes
ClapTrap::ClapTrap() : name("ClapTrap"), hitPoints(10), energyPoints(10), attackDamage(0) {
    std::cout << "Default ClapTrap is constructed!" << std::endl;
}

// Named constructor
ClapTrap::ClapTrap(const std::string& _name) : name(_name), hitPoints(10), energyPoints(10), attackDamage(0) {
    std::cout << "ClapTrap " << name << " is constructed with "
              << hitPoints << " HP, "
              << energyPoints << " EP, and "
              << attackDamage << " AD." << std::endl;
}

// Destructor
ClapTrap::~ClapTrap() {
    std::cout << "ClapTrap " << name << " is destroyed!" << std::endl;
}

void ClapTrap::attack(const std::string& target) {
    if (hitPoints > 0 && energyPoints > 0) {
        std::cout << "ClapTrap " << name << " attacks " << target
                  << ", causing " << attackDamage << " points of damage!" << std::endl;
        energyPoints--;
    } else {
        std::cout << "ClapTrap " << name << " is out of energy or dead!" << std::endl;
    }
}

void ClapTrap::takeDamage(unsigned int amount) {
    std::cout << "ClapTrap " << name << " takes " << amount << " points of damage!" << std::endl;
    if (amount >= hitPoints) {
        hitPoints = 0;
        std::cout << "ClapTrap " << name << " has died!" << std::endl;
    } else {
        hitPoints -= amount;
    }
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (energyPoints > 0) {
        std::cout << "ClapTrap " << name << " repairs " << amount << " hit points!" << std::endl;
        hitPoints += amount;
        energyPoints--;
    } else {
        std::cout << "ClapTrap " << name << " can't repair because it's out of energy!" << std::endl;
    }
}
