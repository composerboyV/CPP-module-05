/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junkwak <junkwak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 15:16:57 by junkwak           #+#    #+#             */
/*   Updated: 2025/04/17 20:04:16 by junkwak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	FORM_HPP
# define FORM_HPP

#include <iostream>
#include <string>

class	Bureaucrat;
class	GradeTooHighException;
class	GradeTooLowException;

class AForm 
{
	private:
		std::string	_name;
		bool		_signed;
		int			_sign_grade;
		int			_play_grade;
			
	public:
		AForm(std::string name, int grade,int play);
		~AForm();
		AForm(const AForm& other);
		AForm& operator=(const AForm& other);
		std::string const & getName() const;
		int	getSigngrade() const;
		int	getplaygrade() const;
		void	beSigned(const Bureaucrat& other);
		bool	isSigned() const;
};

std::ostream& operator<<(std::ostream& os, const AForm& other);

#endif