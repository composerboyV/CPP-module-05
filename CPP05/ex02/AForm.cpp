/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junkwak <junkwak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 15:17:17 by junkwak           #+#    #+#             */
/*   Updated: 2025/03/31 10:35:46 by junkwak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "GradeTooHighException.hpp"
#include "GradeTooLowException.hpp"
#include <exception>

AForm::AForm(std::string name, int signgrade, int playgrade) : _name(name), _signed(false) ,_sign_grade(signgrade), \
			_play_grade(playgrade)
{
	if (_sign_grade < 1 || _play_grade < 1)
		throw	GradeTooHighException();
	else if (_sign_grade > 150 || _play_grade > 150)
		throw	GradeTooLowException();
	std::cout << "<" << name << ">, _signed " << _signed << "and _sign_grade :" << _sign_grade <<std::endl;
}

AForm::~AForm()
{
}

AForm::AForm(const AForm& other) : _name(other._name), _signed(other._signed) , _sign_grade(other._sign_grade), \
			_play_grade(other._play_grade)
{}

AForm& AForm::operator=(const AForm& other)
{
	if (this != &other)
		this->_signed = other._signed;	
	return *this;
}

std::string const & AForm::getName() const
{
	return this->_name;
}
int	AForm::getSigngrade() const
{
	return (this->_sign_grade);
}
int	AForm::getplaygrade() const
{
	return (this->_play_grade);
}
bool AForm::isSigned() const
{
    return this->_signed;
}
void	AForm::beSigned(const Bureaucrat& other)
{
	if (other.getGrade() <= this->_sign_grade)
		this->_signed = true;
	else
		throw GradeTooLowException();	
}

std::ostream& operator<<(std::ostream& os, const AForm& other)
{
	try {
		os << "<" << other.getName() <<", AForm sign grade " <<other.getSigngrade()
		<< ", AForm play grade "<<other.getplaygrade()<< ", AForm is ";
		if (other.isSigned())
			os<<"signed";
		else
			os<<"not signed";
	}
	catch (const std::exception& e) {
		os<<"Error printing AForm: "<<e.what();
	}
	return os;
}