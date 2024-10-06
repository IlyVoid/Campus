/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quvan-de <quvan-de@student.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 19:46:42 by quvan-de          #+#    #+#             */
/*   Updated: 2024/10/06 19:47:12 by quvan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Classes/Harl.hpp"

int main()
{
    Harl harl;

    std::cout << "[TEST] Harl complains at DEBUG level:" << std::endl;
    harl.complain("DEBUG");

    std::cout << "\n[TEST] Harl complains at INFO level:" << std::endl;
    harl.complain("INFO");

    std::cout << "\n[TEST] Harl complains at WARNING level:" << std::endl;
    harl.complain("WARNING");

    std::cout << "\n[TEST] Harl complains at ERROR level:" << std::endl;
    harl.complain("ERROR");

    std::cout << "\n[TEST] Harl complains with an invalid level:" << std::endl;
    harl.complain("INVALID");

    return 0;
}
