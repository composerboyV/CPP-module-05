/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junkwak <junkwak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 11:20:50 by junkwak           #+#    #+#             */
/*   Updated: 2025/04/18 15:44:06 by junkwak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm("Shrubbery", 145, 137), target()
{}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}
ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("Shrubbery", 145, 137), target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other): AForm(other), target(other.target)
{
}
ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
    if (this != &other)
    {
        AForm::operator=(other);
        this->target = other.target;
    }
    return *this;
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
    if (!this->isSigned())
        throw std::runtime_error("Form is not signed");
    if(executor.getGrade() > this->getplaygrade())
        throw   GradeTooLowException();
        
    std::string mix = this->target + "_shrubbery";
    std::fstream makefile;
    makefile.open(mix.c_str(), std::fstream::out | std::fstream::trunc);
    makefile << "               ,@@@@@@@,                  " << std::endl;
    makefile << "       ,,,.   ,@@@@@@/@@,  .oo8888o.      " << std::endl;
    makefile << "    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o     " << std::endl;
    makefile << "   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'    " << std::endl;
    makefile << "   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'    " << std::endl;
    makefile << "   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'     " << std::endl;
    makefile << "   `&%\\ ` /%&'    |.|        \\ '|8'       " << std::endl;
    makefile << "       |o|        | |         | |         " << std::endl;
    makefile << "       |.|        | |         | |         " << std::endl;
    makefile << "    \\/ ._\\//_/__/  ,\\_//__\\/.  \\_//__/_   " << std::endl;
    makefile << std::endl;
    makefile << "    ===================================    " << std::endl;
    makefile.close();
}