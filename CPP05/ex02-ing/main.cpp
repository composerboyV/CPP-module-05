/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junkwak <junkwak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 11:20:37 by junkwak           #+#    #+#             */
/*   Updated: 2025/04/17 20:06:58 by junkwak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Bureaucrat.hpp"
#include "./AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
{
    std::cout<<"----------------------------------------------------------"<<std::endl;
    Bureaucrat test3("test3", 1);
    Bureaucrat test4("test4", 140);
    AForm *pol[3];
    pol[0] = new ShrubberyCreationForm("Shrubbery");
    pol[1] = new RobotomyRequestForm("Robot");
    pol[2] = new PresidentialPardonForm("Pardon");
    srand(getpid());
    try
    {
        int random = rand() % 3;
        test3.signForm(*pol[random]);
        test3.executeForm(*pol[random]);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    catch(const char *e)
    {
        std::cerr << e << '\n';
    }
    for (int i = 0; i < 3; i++)
        delete pol[i];
    return (0);
}
}