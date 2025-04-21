/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junkwak <junkwak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 15:16:57 by junkwak           #+#    #+#             */
/*   Updated: 2025/04/18 15:21:42 by junkwak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	AFORM_HPP
# define AFORM_HPP

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"
#include "GradeTooHighException.hpp"
#include "GradeTooLowException.hpp"

class	Bureaucrat;
class	GradeTooHighException;
class	GradeTooLowException;

class AForm 
{
	protected:
		std::string	_name;
		bool		_signed;
		int			_sign_grade;
		int			_play_grade;
			
	public:
		AForm(std::string name, int grade,int play);
		virtual ~AForm();
		AForm(const AForm& other);
		AForm& operator=(const AForm& other);
		std::string const & getName() const;
		int	getSigngrade() const;
		int	getplaygrade() const;
		void	beSigned(const Bureaucrat& other);
		bool	isSigned() const;
		virtual void	execute(Bureaucrat const & executor) const = 0;
};

std::ostream& operator<<(std::ostream& os, const AForm& other);

#endif