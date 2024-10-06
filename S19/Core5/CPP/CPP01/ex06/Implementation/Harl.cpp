/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quvan-de <quvan-de@student.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 19:54:04 by quvan-de          #+#    #+#             */
/*   Updated: 2024/10/06 19:54:41 by quvan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Classes/Harl.hpp"

// Function to display complaints based on the specified level
void Harl::complain(std::string level)
{
    // Start of switch statement to determine which level to display
    if (level == "DEBUG" || level == "INFO" || level == "WARNING" || level == "ERROR")
    {
        std::cout << "[ " << level << " ]" << std::endl;

        if (level == "DEBUG") {
            std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
        }
        if (level == "DEBUG" || level == "INFO") {
            std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
        }
        if (level == "DEBUG" || level == "INFO" || level == "WARNING") {
            std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
        }
        if (level == "DEBUG" || level == "INFO" || level == "WARNING" || level == "ERROR") {
            std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
        }
    } 
    else {
        std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
    }
}
