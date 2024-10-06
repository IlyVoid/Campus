/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quvan-de <quvan-de@student.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 19:44:23 by quvan-de          #+#    #+#             */
/*   Updated: 2024/10/06 19:46:21 by quvan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Classes/Harl.hpp"

// Private member functions corresponding to the complaint levels

void Harl::debug(void)
{
    std::cout << "[DEBUG]: I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void Harl::info(void)
{
    std::cout << "[INFO]: I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning(void)
{
    std::cout << "[WARNING]: I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error(void)
{
    std::cout << "[ERROR]: This is unacceptable! I want to speak to the manager now." << std::endl;
}

// Public member function that calls the appropriate complaint level
void Harl::complain(std::string level)
{
    // Create an array of member function pointers
    typedef void (Harl::*HarlFunction)(void);
    HarlFunction functions[] = {
        &Harl::debug,
        &Harl::info,
        &Harl::warning,
        &Harl::error
    };

    // Corresponding complaint levels
    std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};

    // Search for the matching level and call the corresponding function
    for (int i = 0; i < 4; i++) {
        if (levels[i] == level) {
            std::cout << "[DEBUG] Calling function for level: " << level << std::endl;
            (this->*functions[i])();
            return;
        }
    }

    std::cout << "[ERROR] Invalid complaint level: " << level << std::endl;
}
