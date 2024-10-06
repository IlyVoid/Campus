/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quvan-de <quvan-de@student.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 18:30:02 by quvan-de          #+#    #+#             */
/*   Updated: 2024/10/06 18:35:56 by quvan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Classes/Weapon.hpp"

Weapon::Weapon(std::string type) : type(type) {
    std::cout << "[DEBUG] Weapon created with type: " << this->type << std::endl;
}

const std::string& Weapon::getType() const {
    return this->type;
}

void Weapon::setType(std::string newType) {
    std::cout << "[DEBUG] Weapon type changed from: " << this->type << " to: " << newType << std::endl;
    this->type = newType;
}

Weapon::~Weapon() {
    std::cout << "[DEBUG] Weapon destroyed with type: " << this->type << std::endl;
}
