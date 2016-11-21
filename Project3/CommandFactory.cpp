#include <vector>
#include <map>

#include "DirCommand.h"
#include "MkdirCommand.h"
#include "RmdirCommand.h"
#include "Shell.h"
#include "CommandFactory.h"

using namespace std;

static const map<string, ShellCommand *(*)(const std::vector<std::string> &_argv) > commandMap = {
	{ "dir",	&DirCommand::create },
	{ "mkdir",	&MkdirCommand::create },
	{ "rmdir",	&RmdirCommand::create }
};

ShellCommand *createCommand(const string &inp){
	vector<string> tokens;
	tokenize(inp, tokens, " ", true);

	if (tokens.size() < 1){
		throw string("invalid command");
	}

	auto mapEntry = commandMap.find(tokens[0]);
	if (mapEntry != commandMap.end()){
		return (*mapEntry->second)(tokens);
	}

	throw string("Unrecognized command " + inp);
}