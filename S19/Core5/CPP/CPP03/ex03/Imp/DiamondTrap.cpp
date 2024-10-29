/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quvan-de <quvan-de@student.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 15:28:09 by quvan-de          #+#    #+#             */
/*   Updated: 2024/10/16 15:34:15 by quvan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Classes/DiamondTrap.hpp"

// Constructor
DiamondTrap::DiamondTrap(const std::string& _name) 
    : ClapTrap(_name + "_clap_name"), FragTrap(_name), ScavTrap(_name), name(_name) {
    
    // No need to re-initialize hitPoints, energyPoints, attackDamage
    std::cout << "DiamondTrap " << name << " is constructed with "
              << hitPoints << " HP, "
              << energyPoints << " EP, and "
              << attackDamage << " AD." << std::endl;
}

// Destructor
DiamondTrap::~DiamondTrap() {
    std::cout << "DiamondTrap " << name << " is destroyed!" << std::endl;
}

// Overridden attack function using ScavTrap's version
void DiamondTrap::attack(const std::string& target) {
    ScavTrap::attack(target); // Calls ScavTrap's attack method
}

// Special function to display both DiamondTrap and ClapTrap names
void DiamondTrap::whoAmI() {
    std::cout << "DiamondTrap name: " << name << ", ClapTrap name: " << ClapTrap::name << std::endl;
}
