/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbousset <hbousset@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 15:24:43 by hbousset          #+#    #+#             */
/*   Updated: 2025/11/14 22:02:28 by hbousset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		const std::string	_name;
		bool				_isSigned;
		const int			_signGrade;
		const int			_executeGrade;
		static const int	GRADE_MIN = 1;
		static const int 	GRADE_MAX = 150;
	public:
		Form(const std::string &name, int signGrade, int executeGrade);
		Form(const Form &other);
		Form& operator=(const Form &other);
		~Form();
		void 				beSigned(const Bureaucrat &signer);
		const std::string&	getName(void)const;
		bool				getIsSigned(void)const;
		int 				getSignGrade(void)const;
		int 				getExecGrade(void)const;

	class GradeTooHighException : public std::exception
	{
		public:
			const char* what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
		public:
			const char* what() const throw();
	};
};

std::ostream& operator<<(std::ostream& os, const Form& f);

