/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quvan-de <quvan-de@student.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 00:22:05 by quvan-de          #+#    #+#             */
/*   Updated: 2024/10/06 17:36:31 by quvan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Classes/zombie.hpp"

int main(void)
{
    std::cout << "Members of the horde spawn uninitialised" << std::endl;
    Zombie *horde = zombieHorde(10, "ZombieHorde");
    std::cout << "\nThe horde let's their prescence be known" << std::endl;
    for (int i = 0; i < 10; i++)
        horde[i].announce();
    std::cout << "\nKill the horde to fix mem leaks" << std::endl;
    delete[] horde;
}
