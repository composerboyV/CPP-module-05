/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junkwak <junkwak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 14:57:14 by junkwak           #+#    #+#             */
/*   Updated: 2025/04/17 20:03:51 by junkwak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	BUREAUCRAT_HPP
# define	BUREAUCRAT_HPP

#include <iostream>
#include <exception>
#include <string>

class	Form;
class GradeTooHighException;
class GradeTooLowException;


class Bureaucrat
{
	private:
		std::string _name;
		int			_grade;
	public:
		Bureaucrat(std::string name, int grade);
		~Bureaucrat();
		Bureaucrat(const Bureaucrat& other);
		Bureaucrat& operator=(const Bureaucrat& other);
		std::string const & getName() const;
		int	getGrade() const;
		int	incrementGrade();
		int	decrementGrade();
		void	signForm(Form& form);

};
std::ostream& operator<<(std::ostream& os, const Bureaucrat& other);

#endif