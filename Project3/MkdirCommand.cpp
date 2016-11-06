#include <direct.h>
#include <vector>
#include <string>
#include "Shell.h"
#include "MkdirCommand.h"

using namespace std;

void MkdirCommand::execute(std::istream &in, std::ostream &out){
	vector<string> tokens;
	tokenize(command, tokens, " ", true);

	if (_mkdir(tokens[1].c_str()) == 0)
	{
		cout << "DIRECTORY " << tokens[1] << " created" << endl;
	}
	else
	{
		char error_buffer[256];
		strerror_s(error_buffer, sizeof(error_buffer), errno);
		cout << "problem creating directory due to error " << error_buffer << endl;
	}
}