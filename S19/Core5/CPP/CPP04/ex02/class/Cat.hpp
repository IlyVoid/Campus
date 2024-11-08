/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quvan-de <quvan-de@student.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 03:56:08 by quvan-de          #+#    #+#             */
/*   Updated: 2024/10/29 03:56:08 by quvan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

class   Cat : public Animal
{
    public:
        // Constructor
        Cat(void);

        // Copy Constructor
        Cat(const Cat& other);

        // Copy Assignment
        Cat& operator = (const Cat& other);

        // Meower
        void makeSound(void) const;

        // Setter
        void    setIdea(std::string, int i);

        // Getters
        std::string getIdea(int i) const;
        Brain* getBrainAddress(void) const;

        // Destructor
        ~Cat(void);

    private:
        Brain* m_brain;
};

#endif
