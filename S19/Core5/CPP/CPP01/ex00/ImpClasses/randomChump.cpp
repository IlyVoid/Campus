/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quvan-de <quvan-de@student.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 00:20:34 by quvan-de          #+#    #+#             */
/*   Updated: 2024/10/06 00:21:50 by quvan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Classes/zombie.hpp"

void	randomChump(std::string name) {
	Zombie stackZombie(name);
	stackZombie.announce();
}
