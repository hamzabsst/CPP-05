/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbousset <hbousset@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 15:24:45 by hbousset          #+#    #+#             */
/*   Updated: 2025/11/14 22:48:52 by hbousset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

const char* Form::GradeTooHighException::what() const throw()
{
	return "Form::GradeTooHighException";
}

const char* Form::GradeTooLowException::what() const throw()
{
	return "Form::GradeTooLowException";
}

Form::Form(const std::string &name, int signGrade, int executeGrade)
	: _name(name), _isSigned(false), _signGrade(signGrade), _executeGrade(executeGrade)
{
	if (_signGrade < GRADE_MIN || _executeGrade < GRADE_MIN)
		throw GradeTooHighException();
	if (_signGrade > GRADE_MAX || _executeGrade > GRADE_MAX)
		throw GradeTooLowException();
}

Form::Form(const Form &other)
	:	_name(other._name), _isSigned(other._isSigned),
		_signGrade(other._signGrade), _executeGrade(other._executeGrade){}

Form& Form::operator=(const Form &other)
{
	if (this != &other)
		_isSigned = other._isSigned;
	return *this;
}

Form::~Form(){}

void Form::beSigned(const Bureaucrat &signer)
{
	if (signer.getGrade() > _signGrade)
		throw GradeTooLowException();
	_isSigned = true;
}

const std::string& Form::getName(void)const
{
	return _name;
}

bool Form::getIsSigned(void)const
{
	return _isSigned;
}

int Form::getSignGrade(void)const
{
	return _signGrade;
}

int Form::getExecGrade(void)const
{
	return _executeGrade;
}

std::ostream& operator<<(std::ostream& os, const Form& f)
{
	os << "Form " << f.getName()
		<< ", signed: " << (f.getIsSigned() ? "yes" : "no")
		<< ", sign grade: " << f.getSignGrade()
		<< ", exec grade: " << f.getExecGrade();
	return os;
}
