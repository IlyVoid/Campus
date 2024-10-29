/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quvan-de <quvan-de@student.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 03:56:07 by quvan-de          #+#    #+#             */
/*   Updated: 2024/10/29 03:56:07 by quvan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

class   Brain
{
    public:
        // Constructor
        Brain(void);

        // Copy Constructor
        Brain(const Brain& other);

        // Copy Assignment
        Brain& operator = (const Brain& other);

        // Setter
        void    ideaSetter(std::string idea, int i);

        // Getter
        const std::string*    ideaGetter(int i);

        // Destructor
        ~Brain(void);

    private:
        std::string m_ideas[100];
};

#endif
