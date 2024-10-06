/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quvan-de <quvan-de@student.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 19:43:40 by quvan-de          #+#    #+#             */
/*   Updated: 2024/10/06 19:43:47 by quvan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

#include <iostream>
#include <string>

class Harl
{
    private:
        // Member functions for each complaint level
        void debug(void);
        void info(void);
        void warning(void);
        void error(void);

    public:
        // Public function to complain based on the level
        void complain(std::string level);
};

#endif
