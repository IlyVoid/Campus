/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quvan-de <quvan-de@student.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 14:33:57 by quvan-de          #+#    #+#             */
/*   Updated: 2024/10/16 14:34:20 by quvan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Classes/ClapTrap.hpp"

int main() {
    ClapTrap clap("Clappy");

    clap.attack("Target1");
    clap.takeDamage(5);
    clap.beRepaired(3);
    clap.takeDamage(10);
    clap.beRepaired(5);
    clap.attack("Target2");

    return 0;
}
