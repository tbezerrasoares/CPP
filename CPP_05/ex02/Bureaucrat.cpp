/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbezerra <tbezerra@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 17:42:11 by tbezerra          #+#    #+#             */
/*   Updated: 2025/07/12 18:34:47 by tbezerra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat() : name("Default"), grade(150) {}

Bureaucrat::Bureaucrat(const std::string& name, int grade) : name(name) {
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
	this->grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : name(other.name), grade(other.grade) {}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
	if (this != &other)
		this->grade = other.grade;
	return *this;
}

Bureaucrat::~Bureaucrat() {}

std::string Bureaucrat::getName() const { return name; }
int Bureaucrat::getGrade() const { return grade; }

void Bureaucrat::incrementGrade() {
	if (grade <= 1)
		throw GradeTooHighException();
	grade--;
}

void Bureaucrat::decrementGrade() {
	if (grade >= 150)
		throw GradeTooLowException();
	grade++;
}

void Bureaucrat::signForm(AForm& form) const {
	try {
		form.beSigned(*this);
		std::cout << name << " signed " << form.getName() << std::endl;
	} catch (std::exception& e) {
		std::cout << name << " couldn't sign " << form.getName() << " because " << e.what() << std::endl;
	}
}

void Bureaucrat::executeForm(const AForm& form) const {
	try {
		form.execute(*this);
		std::cout << name << " executed " << form.getName() << std::endl;
	} catch (std::exception& e) {
		std::cout << name << " couldn't execute " << form.getName() << " because " << e.what() << std::endl;
	}
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return "Bureaucrat: grade too high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return "Bureaucrat: grade too low";
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b) {
	os << b.getName() << ", bureaucrat grade " << b.getGrade();
	return os;
}
