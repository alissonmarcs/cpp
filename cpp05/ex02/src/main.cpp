#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "print.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

namespace Tests
{
  void creation_grades()
  {
   PresidentialPardonForm pardon("pardon");
   ShrubberyCreationForm tree("tree");
   RobotomyRequestForm robot("robot");

   print (CYAN SUB_TITTLE "Shrubbery\n" RESET); 
   print ("Sign grade: " << tree.getSignGrade());
   print ("Exec grade: " << tree.getExecGrade());

   print (CYAN SUB_TITTLE "Robotomy\n" RESET); 
   print ("Sign grade: " << robot.getSignGrade());
   print ("Exec grade: " << robot.getExecGrade());

   print (CYAN SUB_TITTLE "Presidential\n" RESET); 
   print ("Sign grade: " << pardon.getSignGrade());
   print ("Exec grade: " << pardon.getExecGrade());
  }

  void form_actions()
  {
    PresidentialPardonForm pardon("pardon");
    ShrubberyCreationForm tree("tree");
    RobotomyRequestForm robot("robot");
    Bureaucrat melvin("melvin", 1);

    pardon.beSigned(melvin);
    tree.beSigned(melvin);
    robot.beSigned(melvin);

    print (CYAN SUB_TITTLE "Shrubbery\n" RESET); 
    tree.execute(melvin);

    print (CYAN SUB_TITTLE "Robotomy\n" RESET); 
    robot.execute(melvin);
    robot.execute(melvin);
    robot.execute(melvin);
    robot.execute(melvin);

    print (CYAN SUB_TITTLE "Presidential\n" RESET); 
    pardon.execute(melvin);
  }

  void execute_exceptions()
  {
    ShrubberyCreationForm tree("tree");
    Bureaucrat melvin ("melvin", 145);

    try
    {
      tree.execute(melvin);
    }
    catch (const std::exception &e)
    {
      print (RED << e.what() << RESET); 
    }

    tree.beSigned(melvin);

    try
    {
      tree.execute(melvin);
    }
    catch (const std::exception &e)
    {
      print (RED << e.what() << RESET); 
    }

    Bureaucrat best ("best", 1);
    tree.execute(best);
  }

  void executeForm()
  {
    ShrubberyCreationForm tree("tree");
    Bureaucrat melvin ("melvin", 145);

    melvin.executeForm(tree);
    tree.beSigned(melvin);
    melvin.executeForm(tree);
    for (int i = 0; i < 10; i++)
      melvin.incrementGrade();
    melvin.executeForm(tree);
  }
}

int
main (void)
{
  print (GREEN TITTLE "Creation Grades" RESET);
  Tests::creation_grades();
  print (GREEN TITTLE "Form Actions" RESET);
  Tests::form_actions();
  print (GREEN TITTLE "Form's Execute Excepions\n" RESET);
  Tests::execute_exceptions();
  print (GREEN TITTLE "Bureaucrat's ExecuteForm\n" RESET);
  Tests::executeForm();
}
