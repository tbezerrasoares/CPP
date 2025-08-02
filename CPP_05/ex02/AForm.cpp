/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbezerra <tbezerra@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 17:42:58 by tbezerra          #+#    #+#             */
/*   Updated: 2025/07/12 18:16:56 by tbezerra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

// Orthodox Canonical Form
AForm::AForm() : name("Unnamed"), isSigned(false), gradeToSign(150), gradeToExecute(150) {}

AForm::AForm(const std::string& name, int gradeToSign, int gradeToExecute)
	: name(name), isSigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute) {
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw GradeTooLowException();
}

AForm::AForm(const AForm& other)
	: name(other.name), isSigned(other.isSigned),
		gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute) {}

AForm& AForm::operator=(const AForm& other) {
	if (this != &other)
		this->isSigned = other.isSigned;
	return *this;
}

AForm::~AForm() {}

std::string AForm::getName() const { return name; }
bool AForm::getIsSigned() const { return isSigned; }
int AForm::getGradeToSign() const { return gradeToSign; }
int AForm::getGradeToExecute() const { return gradeToExecute; }

void AForm::beSigned(const Bureaucrat& b) {
	if (b.getGrade() > gradeToSign)
		throw GradeTooLowException();
	isSigned = true;
}

void AForm::checkExecutability(const Bureaucrat& executor) const {
	if (!isSigned)
		throw FormNotSignedException();
	if (executor.getGrade() > gradeToExecute)
		throw GradeTooLowException();
}

// Exceptions
const char* AForm::GradeTooHighException::what() const throw() {
	return "AForm: grade too high";
}

const char* AForm::GradeTooLowException::what() const throw() {
	return "AForm: grade too low";
}

const char* AForm::FormNotSignedException::what() const throw() {
	return "AForm: form is not signed";
}

// Output operator
std::ostream& operator<<(std::ostream& os, const AForm& f) {
	os << "Form '" << f.getName()
		<< "', signed: " << std::boolalpha << f.getIsSigned()
		<< ", grade to sign: " << f.getGradeToSign()
		<< ", grade to execute: " << f.getGradeToExecute();
	return os;
}
