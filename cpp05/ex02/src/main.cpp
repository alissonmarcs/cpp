#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "print.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

namespace Tests
{
  void grades_at_creation()
  {
   PresidentialPardonForm pardon("pardon");
   ShrubberyCreationForm tree("tree");
   RobotomyRequestForm robot("robot");

   print ("\n\tShrubberyCreationForm\n");
   print ("Sign grade: " << tree.getSignGrade());
   print ("Exec grade: " << tree.getExecGrade());

   print ("\n\tRobotomyRequestForm \n");
   print ("Sign grade: " << robot.getSignGrade());
   print ("Exec grade: " << robot.getExecGrade());

   print ("\n\tPresidentialPardonForm \n");
   print ("Sign grade: " << pardon.getSignGrade());
   print ("Exec grade: " << pardon.getExecGrade());
  }
}

int
main (void)
{
  print (GREEN "\n\t\t" "Grades at creation" RESET);
  Tests::grades_at_creation();
}
