/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quvan-de <quvan-de@student.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 00:07:29 by quvan-de          #+#    #+#             */
/*   Updated: 2024/10/06 17:32:20 by quvan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>

class   Zombie
{
    public:

        // Default constructor
        Zombie(void);

        // String Constructor
        Zombie(std::string name);

        // Destructor
        ~Zombie(void);

        // Add names to the object
        void    setName(std::string name);

        // Couts Brainz message
        void    announce(void);

    private:
        std::string z_name;
};

Zombie* zombieHorde(int N, std::string name);

#endif
