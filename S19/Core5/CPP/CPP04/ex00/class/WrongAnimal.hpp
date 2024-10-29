/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quvan-de <quvan-de@student.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 03:56:02 by quvan-de          #+#    #+#             */
/*   Updated: 2024/10/29 03:56:02 by quvan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

class   WrongAnimal
{
    public:
        // Constructor
        WrongAnimal(void);

        // Copy Constructor
        WrongAnimal(const WrongAnimal& other);

        // Copy Assignment
        WrongAnimal& operator = (const WrongAnimal& other);

        // Type Getter
        std::string getType(void) const;

        // Animal Sound
        void makeSound(void) const;

        // Destructor
        ~WrongAnimal(void);
    
    protected:
        std::string type;
};

#endif
