#include <direct.h>
#include <vector>
#include <string>
#include "Shell.h"
#include "MkdirCommand.h"

using namespace std;

ShellCommand *MkdirCommand::create(const std::vector<std::string> &_argv){
	return new MkdirCommand(_argv);
}

void MkdirCommand::execute(std::istream &in, std::ostream &out){
	if (_mkdir(argv[1].c_str()) == 0)
	{
		cout << "DIRECTORY " << argv[1] << " created" << endl;
	}	else	{
		throwError("problem creating directory due to error ");
	}
}