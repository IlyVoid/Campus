/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quvan-de <quvan-de@student.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 03:56:02 by quvan-de          #+#    #+#             */
/*   Updated: 2024/10/29 03:56:02 by quvan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

class   Dog : public Animal
{
    public:
        // Constructor
        Dog(void);

        // Copy Constructor
        Dog(const Dog& other);

        // Copy Assignment
        Dog& operator = (const Dog& other);

        // Woefer
        void makeSound(void) const;

        // Destructor
        ~Dog(void);
};

#endif
