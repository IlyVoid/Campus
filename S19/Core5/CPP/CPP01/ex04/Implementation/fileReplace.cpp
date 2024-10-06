/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fileReplace.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quvan-de <quvan-de@student.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 19:13:04 by quvan-de          #+#    #+#             */
/*   Updated: 2024/10/06 19:15:04 by quvan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Classes/fileReplace.hpp"

bool FileReplace::replaceInFile(const std::string& filename, const std::string& s1, const std::string& s2) {
    std::cout << "[DEBUG] Starting replacement process." << std::endl;
    std::cout << "[DEBUG] Filename: " << filename << ", String to replace: '" << s1 << "', Replacement string: '" << s2 << "'" << std::endl;

    if (s1.empty()) {
        std::cerr << "[ERROR] The string to replace (s1) cannot be empty." << std::endl;
        return false;
    }

    // Open the input file
    std::ifstream inputFile(filename.c_str());
    if (!inputFile.is_open()) {
        std::cerr << "[ERROR] Could not open file " << filename << std::endl;
        return false;
    }
    std::cout << "[DEBUG] Successfully opened file: " << filename << std::endl;

    // Read the file content into a string
    std::string content((std::istreambuf_iterator<char>(inputFile)), std::istreambuf_iterator<char>());
    inputFile.close();
    std::cout << "[DEBUG] File content loaded. Size: " << content.size() << " characters." << std::endl;

    // Replace occurrences of s1 with s2 in the content
    std::string replacedContent = replaceOccurrences(content, s1, s2);

    // Open the output file
    std::string outputFilename = filename + ".replace";
    std::ofstream outputFile(outputFilename.c_str());
    if (!outputFile.is_open()) {
        std::cerr << "[ERROR] Could not create output file " << outputFilename << std::endl;
        return false;
    }
    std::cout << "[DEBUG] Output file created: " << outputFilename << std::endl;

    // Write the modified content to the output file
    outputFile << replacedContent;
    outputFile.close();
    std::cout << "[DEBUG] Modified content written to " << outputFilename << std::endl;

    std::cout << "[DEBUG] Replacement complete." << std::endl;
    return true;
}

std::string FileReplace::replaceOccurrences(const std::string& content, const std::string& s1, const std::string& s2) {
    std::cout << "[DEBUG] Starting string replacement." << std::endl;
    std::cout << "[DEBUG] Looking for occurrences of: '" << s1 << "' to replace with '" << s2 << "'." << std::endl;

    std::string result;
    size_t pos = 0;
    size_t found;
    int replacementCount = 0;

    // Loop through the content, finding occurrences of s1
    while ((found = content.find(s1, pos)) != std::string::npos) {
        // Append the part before the found occurrence and the replacement
        result.append(content, pos, found - pos);
        result.append(s2);
        pos = found + s1.length();
        replacementCount++;
        std::cout << "[DEBUG] Replaced occurrence at position " << found << std::endl;
    }

    // Append the rest of the content after the last occurrence
    result.append(content, pos, content.length() - pos);
    std::cout << "[DEBUG] Replacement finished. Total replacements made: " << replacementCount << std::endl;

    return result;
}
