/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbezerra <tbezerra@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 15:24:53 by tbezerra          #+#    #+#             */
/*   Updated: 2025/07/12 16:09:37 by tbezerra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : name("Unnamed"), isSigned(false), gradeToSign(150), gradeToExecute(150) {}

Form::Form(const std::string& name, int gradeToSign, int gradeToExecute)
	: name(name), isSigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute) {
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw GradeTooLowException();
}

Form::Form(const Form& other)
	: name(other.name), isSigned(other.isSigned),
		gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute) {}

Form& Form::operator=(const Form& other) {
	if (this != &other)
		this->isSigned = other.isSigned;
	return *this;
}

Form::~Form() {}

std::string Form::getName() const { return name; }
bool Form::getIsSigned() const { return isSigned; }
int Form::getGradeToSign() const { return gradeToSign; }
int Form::getGradeToExecute() const { return gradeToExecute; }

void Form::beSigned(const Bureaucrat& bureaucrat) {
	if (bureaucrat.getGrade() > gradeToSign)
		throw GradeTooLowException();
	isSigned = true;
}

const char* Form::GradeTooHighException::what() const throw() {
	return "Form: grade too high";
}

const char* Form::GradeTooLowException::what() const throw() {
	return "Form: grade too low";
}

std::ostream& operator<<(std::ostream& os, const Form& f) {
	os << "Form '" << f.getName() << "', signed: " << std::boolalpha << f.getIsSigned()
		<< ", grade to sign: " << f.getGradeToSign()
		<< ", grade to execute: " << f.getGradeToExecute() << ".";
	return os;
}
