#include <direct.h>
#include <vector>
#include <string>
#include "Shell.h"
#include "RmdirCommand.h"

using namespace std;

ShellCommand *RmdirCommand::create(const std::vector<std::string> &_argv){
	return new RmdirCommand(_argv);
}

void RmdirCommand::execute(std::istream &in, std::ostream &out){
	if (_rmdir(argv[1].c_str()) == 0)	{
		cout << "DIRECTORY " << argv[1] << " removed" << endl;
	}	else	{
		throwError( "problem deleting directory due to error " );
	}
}