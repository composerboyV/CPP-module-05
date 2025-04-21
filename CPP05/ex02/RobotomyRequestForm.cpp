/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junkwak <junkwak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 11:20:47 by junkwak           #+#    #+#             */
/*   Updated: 2025/04/18 15:19:36 by junkwak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void) : AForm("robot", 72, 45) , target()
{
}
RobotomyRequestForm::~RobotomyRequestForm()
{
}
RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("robot", 72, 45), target(target)
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : AForm(other), target(other.target)
{
}
RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
    if (this != &other)
    {
        AForm::operator=(other);
        this->target = other.target;
    }
    return *this;
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
    if (!this->isSigned())
        std::cout<<"Form is not signed"<<std::endl;
    else if(executor.getGrade() > this->getplaygrade())
        throw   GradeTooLowException();
    std::cout<<"drillllllll....."<<std::endl;
    if (AForm::_signed == true)
    {
        std::cout<<target<<" repair successfull!"<<std::endl;
    }
    else
    {
        std::cout<<target<<" repair failed!"<<std::endl;
    }
}