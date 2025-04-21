/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junkwak <junkwak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 11:20:44 by junkwak           #+#    #+#             */
/*   Updated: 2025/04/18 15:38:02 by junkwak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "PresidentialPardonForm.hpp"
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm(void) : AForm("pardon",25 ,5) , target()
{
}
PresidentialPardonForm::~PresidentialPardonForm()
{
}
PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("pardon", 25, 5), target(target)
{
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) : AForm(other), target(other.target)
{
}
PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
    if (this != &other)
    {
        AForm::operator=(other);
        this->target = other.target;
    }
    return *this;
}



void    PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
    if (!this->isSigned())
    {
        throw std::runtime_error("check is Signed[President]");
    }
    if (executor.getGrade() > this->getplaygrade())
        throw GradeTooLowException();
    else
    {
        std::cout<<"<"<<target<<"> has been pardoned by Zaphod Beeblebrox"<<std::endl;
    }
}



