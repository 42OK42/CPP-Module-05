/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okrahl <okrahl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 14:41:21 by okrahl            #+#    #+#             */
/*   Updated: 2024/11/04 16:25:48 by okrahl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <string>
#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	public:
		class GradeTooHighException : public std::exception
		{
			const char* what() const throw()
			{
				return "Form grade is too high!";
			}
		};

		class GradeTooLowException : public std::exception
		{
			const char* what() const throw()
			{
				return "Form grade is too low!";
			}
		};

		class FormNotSignedException : public std::exception
		{
			const char* what() const throw()
			{
				return "Form is not signed!";
			}
		};

		AForm(const std::string& name, int gradeToSign, int gradeToExecute);
		virtual ~AForm();

		std::string getName() const;
		bool getIsSigned() const;
		int getGradeToSign() const;
		int getGradeToExecute() const;

		void beSigned(const Bureaucrat& bureaucrat);
		virtual void execute(Bureaucrat const & executor) const = 0;

	protected:
		void checkExecutionRequirements(Bureaucrat const & executor) const;

	private:
		const std::string name;
		bool isSigned;
		const int gradeToSign;
		const int gradeToExecute;
};

std::ostream& operator<<(std::ostream& os, const AForm& form);

#endif