/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quvan-de <quvan-de@student.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 18:44:39 by quvan-de          #+#    #+#             */
/*   Updated: 2024/10/06 19:00:22 by quvan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Classes/Weapon.hpp"
#include "Classes/HumanA.hpp"
#include "Classes/HumanB.hpp"

int main() {
    std::cout << "[DEBUG] Starting the program\n" << std::endl;

    {
        Weapon club = Weapon("crude spiked club");
        HumanA bob("Bob", club);
        bob.attack();
        club.setType("AK47");
        bob.attack();
    }

    std::cout << "\n[DEBUG] Moving on to HumanB test\n" << std::endl;

    {
        Weapon club = Weapon("crude spiked club");
        HumanB jim("Jim");
        jim.attack();
        jim.setWeapon(club);
        jim.attack();
        club.setType(".50cal Berretta");
        jim.attack();
    }

    std::cout << "\n[DEBUG] Ending the program" << std::endl;

    return 0;
}
