/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quvan-de <quvan-de@student.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 12:26:07 by quvan-de          #+#    #+#             */
/*   Updated: 2024/10/16 14:35:39 by quvan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Classes/ClapTrap.hpp"

// Constructor
ClapTrap::ClapTrap(const std::string& _name) : name(_name), hitPoints(10), energyPoints(10), attackDamage(0) {
	std::cout << "ClapTrap " << name << ": is born with" << std::endl;
	std::cout << "[" << hitPoints << "]" << " hit points," << std::endl;
	std::cout << "[" << energyPoints << "]" << " energy points and" << std::endl;
	std::cout << "[" << attackDamage << "]" << " attack damage." << std::endl;
}

// Destructor
ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap " << name << ": has been terminated" << std::endl;
}

// Attack func
void ClapTrap::attack(const std::string& target) {
	if (hitPoints > 0 && energyPoints > 0) {
		std::cout << "ClapTrap " << name << " attacks: " << target  << ", causing " << attackDamage << " points of damage!" << std::endl;
        energyPoints--;
    } else if (hitPoints <= 0) {
        std::cout << "ClapTrap " << name << " cannot attack because it has no hit points!" << std::endl;
    } else {
        std::cout << "ClapTrap " << name << " cannot attack because it has no energy points!" << std::endl;
    }
}

// Take damage function
void ClapTrap::takeDamage(unsigned int amount) {
    if (hitPoints > 0) {
        std::cout << "ClapTrap " << name << " takes " << amount << " points of damage!" << std::endl;
        if (amount >= hitPoints) {
            hitPoints = 0;
            std::cout << "ClapTrap " << name << " is now dead!" << std::endl;
        } else {
            hitPoints -= amount;
        }
    } else {
        std::cout << "ClapTrap " << name << " is already dead!" << std::endl;
    }
}

// Repair function
void ClapTrap::beRepaired(unsigned int amount) {
    if (hitPoints > 0 && energyPoints > 0) {
        std::cout << "ClapTrap " << name << " repairs itself, recovering " << amount << " hit points!" << std::endl;
        hitPoints += amount;
        energyPoints--;
    } else if (hitPoints <= 0) {
        std::cout << "ClapTrap " << name << " cannot be repaired because it is dead!" << std::endl;
    } else {
        std::cout << "ClapTrap " << name << " cannot be repaired because it has no energy points!" << std::endl;
    }
}
