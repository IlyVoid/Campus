/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fileReplace.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quvan-de <quvan-de@student.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 19:10:40 by quvan-de          #+#    #+#             */
/*   Updated: 2024/10/06 19:10:45 by quvan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILEREPLACE_HPP
#define FILEREPLACE_HPP

#include <string>
#include <fstream>
#include <iostream>

class FileReplace {
public:
    static bool replaceInFile(const std::string& filename, const std::string& s1, const std::string& s2);

private:
    static std::string replaceOccurrences(const std::string& content, const std::string& s1, const std::string& s2);
};

#endif
