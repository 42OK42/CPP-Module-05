/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okrahl <okrahl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:29:22 by okrahl            #+#    #+#             */
/*   Updated: 2024/11/06 18:27:42 by okrahl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <stdexcept>
#include <string>
#include <sstream>
#include <cstdlib>
#include "Form.hpp"

class Form;

class Bureaucrat
{
	public:
		class GradeTooHighException : public std::exception {
		public:
			GradeTooHighException(int grade);
			virtual ~GradeTooHighException() throw();
			const char* what() const throw();
		
		private:
			int grade;
			mutable std::string message;
		};

		class GradeTooLowException : public std::exception {
		public:
			GradeTooLowException(int grade);
			virtual ~GradeTooLowException() throw();
			const char* what() const throw();
		
		private:
			int grade;
			mutable std::string message;
		};

		Bureaucrat(const std::string& name, int grade);
		Bureaucrat(const Bureaucrat& other);
		Bureaucrat& operator=(const Bureaucrat& other);
		~Bureaucrat();

		const std::string& getName() const;
		int getGrade() const;
		void incrementGrade();
		void decrementGrade();
		void signForm(Form& form) const;

	private:
		const std::string _name;
		int _grade;
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);

#endif