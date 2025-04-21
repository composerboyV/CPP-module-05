/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junkwak <junkwak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 11:20:56 by junkwak           #+#    #+#             */
/*   Updated: 2025/04/18 15:21:50 by junkwak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define    SHRUBBERYCREATIONFORM_HPP

#include <iostream>
#include "AForm.hpp"
#include "GradeTooHighException.hpp"
#include "GradeTooLowException.hpp"

class	Bureaucrat;
class	GradeTooHighException;
class	GradeTooLowException;

class ShrubberyCreationForm : public AForm
{
protected :
    std::string target;
public:
    ShrubberyCreationForm(void);
    ~ShrubberyCreationForm();
    ShrubberyCreationForm(const ShrubberyCreationForm& other);
    ShrubberyCreationForm(std::string target);
    ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
    virtual void execute(Bureaucrat const & executor) const;
};


#endif