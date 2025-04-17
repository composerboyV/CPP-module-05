/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junkwak <junkwak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 11:20:44 by junkwak           #+#    #+#             */
/*   Updated: 2025/04/17 11:19:47 by junkwak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
PresidentialPardonForm::PresidentialPardonForm(void)
{
    this->sign = 25;
    this->exec = 5;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other)
{}
PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{}