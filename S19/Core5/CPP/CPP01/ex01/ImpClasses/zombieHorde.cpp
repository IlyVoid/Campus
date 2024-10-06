/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quvan-de <quvan-de@student.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 00:51:09 by quvan-de          #+#    #+#             */
/*   Updated: 2024/10/06 17:44:17 by quvan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Classes/zombie.hpp"
#include <cstdlib>
#include <ctime> 

std::string getRandomName() {
    std::string names[] = {"Zed", "Ghoul", "Walker", "Crawler", "Biter", "Rotter", "Lurker", "FleshEater"};
    int randomIndex = std::rand() % (sizeof(names) / sizeof(names[0]));
    return names[randomIndex];
}

Zombie* zombieHorde(int N, std::string name)
{
    if (N <= 0)
        return NULL;

    // Seed the random number generator
    std::srand(std::time(0));

    // Allocate the horde
    Zombie* horde = new Zombie[N];
    std::cout << "\nRenaming all horde members if necessary" << std::endl;

    for (int i = 0; i < N; i++) {
        if (name == "ZombieHorde") {
            // Assign random name only if the name is "ZombieHorde"
            std::string randomName = getRandomName();
            horde[i].setName(randomName);
        } else {
            // If a different name is passed, assign it as is
            horde[i].setName(name);
        }
    }
    return horde;
}
