/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junkwak <junkwak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 16:27:03 by junkwak           #+#    #+#             */
/*   Updated: 2025/04/18 16:58:41 by junkwak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern(void)
{
    this->str[0] = "shrubbery";
    this->str[1] = "RobotRequest";
    this->str[2] = "Presidnet";
    this->str[3] = "error";
}

Intern::~Intern()
{
    std::cout<<"Intern Constructor!"<<std::endl;
}

Intern::Intern(const Intern& other)
{
    *this = other;
}
Intern& Intern::operator=(const Intern& other)
{
    if (this != &other) {
        for (int i = 0; i < 4; i++) {
            this->str[i] = other.str[i];
        }
    }
    return (*this);
}

AForm*  Intern::makeForm(std::string Form, std::string target)
{
    int index = -1;
    index = (str[0] == Form) ? 0 : index;
    index = (str[1] == Form) ? 1 : index;
    index = (str[2] == Form) ? 2 : index;
    index = (str[3] == Form) ? 3 : index;

    AForm* check_case = NULL;
    switch(index) {
        case 0:
            check_case = new ShrubberyCreationForm(target);
            std::cout<<"Intern create Shrubbry!"<<std::endl;
            break ;
        case 1:
            check_case = new RobotomyRequestForm(target);
            std::cout<<"Intern create Roboto!"<<std::endl;
            break ;
        case 2:
            check_case = new PresidentialPardonForm(target);
            std::cout<<"President!"<<std::endl;
            break ;
        default:
            std::cout<<"Error "<<Form<<"case!"<<std::endl;
            return (NULL);
    }
    return check_case;
}
