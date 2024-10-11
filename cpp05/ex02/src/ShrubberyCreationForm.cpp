#include "ShrubberyCreationForm.hpp"
#include "print.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm()
	: AForm(145, 137, "guest")
{
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string name)
	: AForm(145, 137, name)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) 
	: AForm(other)
{
}

ShrubberyCreationForm &
ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	this->AForm::operator=(other);
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	
}

void
ShrubberyCreationForm::execute(const Bureaucrat & executor) const
{
	if (!isSigned())
		throw AForm::FormNotSignedException();
	else if (executor.getGrade() > getExecGrade())
		throw AForm::GradeTooLowException();
	std::string filename = getName() + "_shrubbery";
	std::ofstream file(filename.c_str());

	file << 
	".....................................................................\n"
	"..............................=.....+@#%*#+-.........................\n"
	".......................**@@#@@@%@*%@@%*%%*+#*%#......................\n"
	"......................%@@@@@@%%#@@@@*#%@@@@@@@@*@%#..................\n"
	".................:-@%%%%@%@@@@@@@@%@@@@%@%%@*@@@@@%#.................\n"
	"................##%#@@#@@@@%%@@@@@@@@@@@@%@@@@@#@%@%*................\n"
	"..............=@%@@@#%@@@@@#@@@@%@%*@@@@@@@@@#@@@@@@#................\n"
	"...............@@@@@@@@@@@@@#@@@@@*@@@@%@@@@@@%@%#%@%@...............\n"
	".............+##@@@@#@@@@%%@@@@@@@@@@@%@@@@@@@@@@@@@@@@#.............\n"
	"............%##%@@%@@@@@@@%@@@@@@@@@@@%@@@%@@@@@@@@@@#@@.............\n"
	"............@@@%@@@@@@@#@@#@@@@@@%@@@@@@@@@@@@@%@#%@@%%##%*..........\n"
	"........%@#@@@@%%@%@@@@@@@@@@@@@@@@@@@@@@@@@@@@@%@@@@@@@%@#%.........\n"
	"........%@@@@@@#@@@@@@@@@@@@%@@@@@@#@@@@%@@@@@%%@@@@@@@@@@%@%........\n"
	"...........@@@+@@@@.@@@@@%@@@@@.@*@+@@@@@%:@@@@@@%@@@@@@@@@.-........\n"
	".............=*..#...@@@@@:@#*@@-@@@.@@:.@....%-=@%@@*#@@@#..........\n"
	".........................+.......@@..@........@@@@...@%..............\n"
	".................................@@@.................................\n"
	".................................+@@.................................\n"
	".................................%@@.................................\n"
	"................................@@@@@................................\n";
	file.close();
	print (getName() << " has been shrubberized successfully.");
}
