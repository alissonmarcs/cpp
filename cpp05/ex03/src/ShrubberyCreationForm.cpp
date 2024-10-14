#include "ShrubberyCreationForm.hpp"
#include "print.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm ()
    : AForm (145, 137, "ShrubberyCreationForm"), _target ("Nobody")
{
}

ShrubberyCreationForm::ShrubberyCreationForm (std::string target)
    : AForm (145, 137, "ShrubberyCreationForm"), _target (target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm (
    const ShrubberyCreationForm &other)
    : AForm (other), _target (other._target)
{
}

ShrubberyCreationForm &
ShrubberyCreationForm::operator= (const ShrubberyCreationForm &other)
{
  this->AForm::operator= (other);
  return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm () {}

std::string
ShrubberyCreationForm::getTarget () const
{
  return _target;
}

void
ShrubberyCreationForm::execute (const Bureaucrat &executor) const
{
  if (!isSigned ())
    throw AForm::FormNotSignedException ();
  else if (executor.getGrade () > getExecGrade ())
    throw Bureaucrat::GradeTooLowException ();
  std::string filename = getTarget () + "_shrubbery";
  std::ofstream file (filename.c_str ());

  file << "..................................................................."
          "..\n"
          "..............................=.....+@#%*#+-......................."
          "..\n"
          ".......................**@@#@@@%@*%@@%*%%*+#*%#...................."
          "..\n"
          "......................%@@@@@@%%#@@@@*#%@@@@@@@@*@%#................"
          "..\n"
          ".................:-@%%%%@%@@@@@@@@%@@@@%@%%@*@@@@@%#..............."
          "..\n"
          "................##%#@@#@@@@%%@@@@@@@@@@@@%@@@@@#@%@%*.............."
          "..\n"
          "..............=@%@@@#%@@@@@#@@@@%@%*@@@@@@@@@#@@@@@@#.............."
          "..\n"
          "...............@@@@@@@@@@@@@#@@@@@*@@@@%@@@@@@%@%#%@%@............."
          "..\n"
          ".............+##@@@@#@@@@%%@@@@@@@@@@@%@@@@@@@@@@@@@@@@#..........."
          "..\n"
          "............%##%@@%@@@@@@@%@@@@@@@@@@@%@@@%@@@@@@@@@@#@@..........."
          "..\n"
          "............@@@%@@@@@@@#@@#@@@@@@%@@@@@@@@@@@@@%@#%@@%%##%*........"
          "..\n"
          "........%@#@@@@%%@%@@@@@@@@@@@@@@@@@@@@@@@@@@@@@%@@@@@@@%@#%......."
          "..\n"
          "........%@@@@@@#@@@@@@@@@@@@%@@@@@@#@@@@%@@@@@%%@@@@@@@@@@%@%......"
          "..\n"
          "...........@@@+@@@@.@@@@@%@@@@@.@*@+@@@@@%:@@@@@@%@@@@@@@@@.-......"
          "..\n"
          ".............=*..#...@@@@@:@#*@@-@@@.@@:.@....%-=@%@@*#@@@#........"
          "..\n"
          ".........................+.......@@..@........@@@@...@%............"
          "..\n"
          ".................................@@@..............................."
          "..\n"
          ".................................+@@..............................."
          "..\n"
          ".................................%@@..............................."
          "..\n"
          "................................@@@@@.............................."
          "..\n";
  file.close ();
  print (_target << " has been shrubberized successfully.");
}
