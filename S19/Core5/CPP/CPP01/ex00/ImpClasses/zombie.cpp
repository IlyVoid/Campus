/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quvan-de <quvan-de@student.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 00:12:41 by quvan-de          #+#    #+#             */
/*   Updated: 2024/10/06 00:43:26 by quvan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Classes/zombie.hpp"

Zombie::Zombie(std::string zombieName) : name(zombieName) {
	std::cout << name << " Has been created." << std::endl;
}

Zombie::~Zombie() {
	std::cout << name << " Has been killed." << std::endl;
}

void Zombie::announce() {
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
