/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quvan-de <quvan-de@student.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 00:22:05 by quvan-de          #+#    #+#             */
/*   Updated: 2024/10/06 00:41:29 by quvan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Classes/zombie.hpp"

Zombie* newZombie(std::string name);
void	randomChump(std::string name);

int	main() {
	std::cout << "\n=== Heap Zombie Life Cycle ===\n";
	Zombie* heapZombie = newZombie("HeapZombie");
	heapZombie->announce();
	delete heapZombie;

	std::cout << "\n=== Stack Zombie Life Cycle ===\n";
	randomChump("StackZombie");
	return 0;
}
