/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbousset <hbousset@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 16:11:54 by hbousset          #+#    #+#             */
/*   Updated: 2025/11/14 23:30:51 by hbousset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

const char * Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Bureaucrat::GradeTooHighException";
}

const char * Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Bureaucrat::GradeTooLowException";
}

Bureaucrat::Bureaucrat(const std::string &name, int grade):_name(name),_grade(grade)
{
	if (_grade < GRADE_MIN)
		throw GradeTooHighException();
	if (_grade > GRADE_MAX)
		throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat &other):_name(other._name), _grade(other._grade){}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &other)
{
	if (this != &other)
	{
		_grade = other._grade;
	}
	return *this;
}

Bureaucrat::~Bureaucrat(){}

const std::string&	Bureaucrat::getName() const{return _name;}
int					Bureaucrat::getGrade() const {return _grade;}

void	Bureaucrat::incGrade()
{
	if (_grade - 1 < GRADE_MIN)
		throw GradeTooHighException();
	_grade--;
}

void	Bureaucrat::decGrade()
{
	if (_grade + 1 > GRADE_MAX)
		throw GradeTooLowException();
	_grade++;
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b)
{
	os << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
	return os;
}

