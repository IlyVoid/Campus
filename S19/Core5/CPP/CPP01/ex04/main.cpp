/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quvan-de <quvan-de@student.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 19:16:51 by quvan-de          #+#    #+#             */
/*   Updated: 2024/10/06 19:17:15 by quvan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Classes/fileReplace.hpp"

int main(int argc, char* argv[]) {
    std::cout << "[DEBUG] Program started." << std::endl;

    if (argc != 4) {
        std::cerr << "[ERROR] Usage: " << argv[0] << " <filename> <string1> <string2>" << std::endl;
        return 1;
    }

    std::string filename = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];

    std::cout << "[DEBUG] Command-line arguments received." << std::endl;
    std::cout << "[DEBUG] Filename: " << filename << ", String1: '" << s1 << "', String2: '" << s2 << "'" << std::endl;

    if (!FileReplace::replaceInFile(filename, s1, s2)) {
        std::cerr << "[ERROR] Replacement failed." << std::endl;
        return 1;
    }

    std::cout << "[DEBUG] Program finished successfully." << std::endl;
    return 0;
}
