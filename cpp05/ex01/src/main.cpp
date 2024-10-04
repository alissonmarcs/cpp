#include "print.hpp"
#include "Bureaucrat.hpp"
#include "Form.hpp"

namespace Tests
{
	void signForm()
	{
		Bureaucrat jose("jose", 100);
		Form job(42, 90, "job");

		print (RED "Bureaucrat " << jose.getName() <<  " with low grade try to sign a form" RESET);
		jose.signForm(job);


		Bureaucrat carla("carla", 30);
		Form car(40, 89, "car");

		print (RED "Bureaucrat " << jose.getName() <<  " with low grade try to sign a form" RESET);
		carla.signForm(car);
	}

	void formExceptions()
	{
		try
		{
			Form hight(0, 100, "TestForm");
		}
		catch(const Form::GradeTooHighException& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
}

int main(void)
{
	Tests::signForm();
	Tests::formExceptions();
}
