/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbezerra <tbezerra@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 14:05:46 by tbezerra          #+#    #+#             */
/*   Updated: 2025/07/12 15:49:52 by tbezerra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <stdexcept>
#include <string>

class Form; // Forward declaration

class Bureaucrat {
private:
	const std::string name;
	int grade;

public:
	// Orthodox Canonical Form
	Bureaucrat();
	Bureaucrat(const std::string& name, int grade);
	Bureaucrat(const Bureaucrat& other);
	Bureaucrat& operator=(const Bureaucrat& other);
	~Bureaucrat();

	// Getters
	std::string getName() const;
	int getGrade() const;

	// Grade control
	void incrementGrade();
	void decrementGrade();

	void signForm(Form& form) const;

	// Exceptions
	class GradeTooHighException : public std::exception {
		public:
			const char* what() const throw();
	};

	class GradeTooLowException : public std::exception {
		public:
			const char* what() const throw();
	};
};

// Overload of <<
std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);

#endif
