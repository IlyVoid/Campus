/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quvan-de <quvan-de@student.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 14:33:57 by quvan-de          #+#    #+#             */
/*   Updated: 2024/10/16 15:18:55 by quvan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Classes/ScavTrap.hpp"

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

    return 0;
}
