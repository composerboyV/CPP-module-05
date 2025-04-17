/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junkwak <junkwak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 14:57:26 by junkwak           #+#    #+#             */
/*   Updated: 2025/04/17 20:10:24 by junkwak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "GradeTooHighException.hpp"
#include "GradeTooLowException.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade)
{
	if (_grade < 1)
		throw	GradeTooHighException();
	else if (_grade > 150)
		throw	GradeTooLowException();
	std::cout << "<" << name << ">, bureaucrat grade" << _grade << std::endl;
}

Bureaucrat::~Bureaucrat()
{
}

Bureaucrat::Bureaucrat(const Bureaucrat& other)
{
	if (this != &other) {
		this->_name = other._name;
		this->_grade = other._grade;
	}

}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
	if (this != &other) {
		this->_name = other._name;
		this->_grade = other._grade;
	}
	return *this;
}

std::string const & Bureaucrat::getName() const
{
	return this->_name;
}
int	Bureaucrat::getGrade() const
{
	return this->_grade;
}

int	Bureaucrat::incrementGrade()
{
	if (_grade <= 1) {
		GradeTooLowException();
	}

	return (this->_grade -= 1);

}
int	Bureaucrat::decrementGrade()
{
	this->_grade += 1;
	if (_grade > 150)
		throw	GradeTooLowException();
	return (_grade);
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& other)
{
	os << "<" << other.getName() << ">, bureaucrat grade " << other.getGrade();
	return os;
}

void	Bureaucrat::signForm(AForm& form)
{
	try
	{
		form.beSigned(*this);
		std::cout<<"<"<<getName()<<"> signed" <<form.getName()<<std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout<<"<"<<getName()<<"> couldn`t sign <"<<form.getName()
		<<"> because " <<e.what()<<std::endl;
	}
}

void	Bureaucrat::executed(AForm const &form)
{
	
}
