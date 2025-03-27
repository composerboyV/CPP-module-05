/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GradeTooLowException.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junkwak <junkwak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 15:35:15 by junkwak           #+#    #+#             */
/*   Updated: 2025/03/27 19:07:54 by junkwak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	GRADETOOLOWEXCEPTION_HPP
# define	GRADETOOLOWEXCEPTION_HPP

// #include "Bureaucrat.hpp"
#include <exception>
class GradeTooLowException : public std::exception
{
	public:
		const char* what() const throw();

};

#endif