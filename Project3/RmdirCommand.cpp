#include <direct.h>
#include <vector>
#include <string>
#include "Shell.h"
#include "RmdirCommand.h"

using namespace std;

ShellCommand *RmdirCommand::create(const std::string &cmd){
	return new RmdirCommand(cmd);
}


void RmdirCommand::execute(std::istream &in, std::ostream &out){
	vector<string> tokens;
	tokenize(command, tokens, " ", true);

	if (_rmdir(tokens[1].c_str()) == 0)
	{
		cout << "DIRECTORY " << tokens[1] << " removed" << endl;
	}
	else
	{
		char error_buffer[256];
		strerror_s(error_buffer, sizeof(error_buffer), errno);
		cout << "problem deleting directory due to error " << error_buffer << endl;
	}
}