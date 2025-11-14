/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbousset <hbousset@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 15:24:45 by hbousset          #+#    #+#             */
/*   Updated: 2025/11/14 22:48:52 by hbousset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/AForm.hpp"

const char* AForm::GradeTooHighException::what() const throw()
{
	return "AForm::GradeTooHighException";
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return "AForm::GradeTooLowException";
}

const char* AForm::FormNotSignedException::what() const throw()
{
	return "AForm::FormNotSignedException";
}

AForm::AForm(const std::string &name, int signGrade, int executeGrade)
	: _name(name), _isSigned(false), _signGrade(signGrade), _executeGrade(executeGrade)
{
	if (_signGrade < GRADE_MIN || _executeGrade < GRADE_MIN)
		throw GradeTooHighException();
	if (_signGrade > GRADE_MAX || _executeGrade > GRADE_MAX)
		throw GradeTooLowException();
}

AForm::AForm(const AForm &other)
	:	_name(other._name), _isSigned(other._isSigned),
		_signGrade(other._signGrade), _executeGrade(other._executeGrade){}

AForm& AForm::operator=(const AForm &other)
{
	if (this != &other)
		_isSigned = other._isSigned;
	return *this;
}

AForm::~AForm(){}

void AForm::beSigned(const Bureaucrat &signer)
{
	if (signer.getGrade() > _signGrade)
		throw GradeTooLowException();
	_isSigned = true;
}

const std::string& AForm::getName(void)const {return _name;}

bool AForm::getIsSigned(void)const {return _isSigned;}

int AForm::getSignGrade(void)const {return _signGrade;}

int AForm::getExecGrade(void)const {return _executeGrade;}

void AForm::execute(const Bureaucrat& executor) const
{
	if (!_isSigned)
		throw FormNotSignedException();
	if (executor.getGrade() > _executeGrade)
		throw GradeTooLowException();
	executeAction();
}

std::ostream& operator<<(std::ostream& os, const AForm& f)
{
	os << "AForm " << f.getName()
		<< ", signed: " << (f.getIsSigned() ? "yes" : "no")
		<< ", sign grade: " << f.getSignGrade()
		<< ", exec grade: " << f.getExecGrade();
	return os;
}
