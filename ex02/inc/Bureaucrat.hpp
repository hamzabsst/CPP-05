/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbousset <hbousset@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 16:11:46 by hbousset          #+#    #+#             */
/*   Updated: 2025/11/14 23:33:12 by hbousset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>
# include <string>
# include <exception>

class AForm;

class Bureaucrat
{
	private:
		const std::string	_name;
		int					_grade;
		static const int GRADE_MIN = 1;
		static const int GRADE_MAX = 150;
	public:
		Bureaucrat(const std::string &name, int grade);
		Bureaucrat(const Bureaucrat &other);
		Bureaucrat& operator=(const Bureaucrat &other);
		~Bureaucrat();
		const std::string&	getName() const;
		int					getGrade() const;
		void				incGrade();
		void				decGrade();
		void				signForm(AForm& form);
		void				executeForm(const AForm& form) const;

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
std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);
