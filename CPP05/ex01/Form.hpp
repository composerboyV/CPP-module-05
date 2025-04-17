/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junkwak <junkwak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 15:16:57 by junkwak           #+#    #+#             */
/*   Updated: 2025/04/17 10:39:19 by junkwak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	FORM_HPP
# define FORM_HPP

#include <iostream>
#include <string>

class	Bureaucrat;
class	GradeTooHighException;
class	GradeTooLowException;

class Form
{
	private:
		std::string	_name;
		bool		_signed;
		int			_sign_grade;
		int			_play_grade;
		
	public:
		Form(std::string name, int grade,int play);
		~Form();
		Form(const Form& other);
		Form& operator=(const Form& other);
		std::string const & getName() const;
		int	getSigngrade() const;
		int	getplaygrade() const;
		void	beSigned(const Bureaucrat& other);
		bool	isSigned() const;
};

std::ostream& operator<<(std::ostream& os, const Form& other);

#endif