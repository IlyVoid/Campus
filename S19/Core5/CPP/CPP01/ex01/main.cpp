/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quvan-de <quvan-de@student.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 00:22:05 by quvan-de          #+#    #+#             */
/*   Updated: 2024/10/06 00:55:45 by quvan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Classes/zombie.hpp"

Zombie* zombieHorde(int N, std::string name);

int	main() {
	int N = 5;
	Zombie* horde = zombieHorde(N, "ZombieHorde");
	for (int i = 0; i < N; ++i) {
		horde[i].announce();
	}
	delete[] horde;
	return 0;
}
