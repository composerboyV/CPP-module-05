/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GradeTooHighException.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junkwak <junkwak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 14:40:22 by junkwak           #+#    #+#             */
/*   Updated: 2025/04/17 10:35:42 by junkwak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	GRADETOOHIGHEXCEPTION_HPP
# define	GRADETOOHIGHEXCEPTION_HPP


#include <exception>

class GradeTooHighException : public std::exception
{
	public:
		const char* what() const throw();
};

#endif