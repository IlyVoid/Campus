/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quvan-de <quvan-de@student.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 14:33:57 by quvan-de          #+#    #+#             */
/*   Updated: 2024/10/16 15:31:07 by quvan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Classes/ScavTrap.hpp"
#include "Classes/FragTrap.hpp"
#include "Classes/DiamondTrap.hpp"

int main() {
    ClapTrap clap("Clappy");

    clap.attack("Target1");
    clap.takeDamage(5);
    clap.beRepaired(3);
    clap.takeDamage(10);
    clap.beRepaired(5);
    clap.attack("Target2");

    std::cout << "\n--- Now introducing ScavTrap! ---\n" << std::endl;

    ScavTrap scav("Scavvy");
    scav.attack("Enemy1");
    scav.takeDamage(30);
    scav.beRepaired(10);
    scav.guardGate();
    scav.takeDamage(100);
    scav.beRepaired(20);

    std::cout << "\n--- Now introducing FragTrap! ---\n" << std::endl;

    FragTrap frag("Fraggy");
    frag.attack("Enemy2");
    frag.takeDamage(50);
    frag.beRepaired(20);
    frag.highFivesGuys();
    frag.takeDamage(200);  // FragTrap should "die" here
    frag.beRepaired(50);   // But it won't work because it's dead

    std::cout << "\n--- Now introducing DiamondTrap! ---\n" << std::endl;

    DiamondTrap diamond("Diamond");
    diamond.attack("Enemy3");
    
    // Explicitly resolve ambiguity
    diamond.ClapTrap::takeDamage(40);  // Specify ClapTrap's takeDamage
    diamond.ClapTrap::beRepaired(30);  // Specify ClapTrap's beRepaired
    diamond.whoAmI();
    diamond.guardGate(); // Inherited from ScavTrap
    diamond.highFivesGuys(); // Inherited from FragTrap
    diamond.ClapTrap::takeDamage(150); // Specify ClapTrap's takeDamage
    diamond.ClapTrap::beRepaired(50);  // Specify ClapTrap's beRepaired

    return 0;
}

