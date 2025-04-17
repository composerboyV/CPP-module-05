/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junkwak <junkwak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 15:17:17 by junkwak           #+#    #+#             */
/*   Updated: 2025/04/17 10:51:20 by junkwak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"
#include "GradeTooHighException.hpp"
#include "GradeTooLowException.hpp"
#include <exception>

Form::Form(std::string name, int signgrade, int playgrade) : _name(name), _signed(false) ,_sign_grade(signgrade), \
			_play_grade(playgrade)
{
	if (_sign_grade < 1 || _play_grade < 1)
		throw	GradeTooHighException();
	else if (_sign_grade > 150 || _play_grade > 150)
		throw	GradeTooLowException();
	// std::cout << "<" << name << ">, Form grade" << _grade << std::endl;
}

Form::~Form()
{
}

Form::Form(const Form& other) : _name(other._name), _signed(other._signed) , _sign_grade(other._sign_grade), \
			_play_grade(other._play_grade)
{}

Form& Form::operator=(const Form& other)
{
	if (this != &other)
		this->_signed = other._signed;	
	return *this;
}

std::string const & Form::getName() const
{
	return this->_name;
}
int	Form::getSigngrade() const
{
	return (this->_sign_grade);
}
int	Form::getplaygrade() const
{
	return (this->_play_grade);
}
bool Form::isSigned() const
{
    return this->_signed;
}
void	Form::beSigned(const Bureaucrat& other)
{
	if (other.getGrade() >= this->_sign_grade)
		this->_signed = true;
	else
		throw GradeTooLowException();	
}

std::ostream& operator<<(std::ostream& os, const Form& other)
{
	try {
		os << "<" << other.getName() <<", form sign grade " <<other.getSigngrade()
		<< ", form play grade "<<other.getplaygrade()<< ", form is ";
		if (other.isSigned())
			os<<"signed";
		else
			os<<"not signed";
	}
	catch (const std::exception& e) {
		os<<"Error printing form: "<<e.what();
	}
	return os;
}