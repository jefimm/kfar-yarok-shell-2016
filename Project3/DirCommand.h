
#pragma once

#include "ShellCommand.h"

class DirCommand : public ShellCommand {
protected:
	DirCommand(const std::vector<std::string> &_argv) : ShellCommand(_argv) {};
public:
	virtual void execute(std::istream &in, std::ostream &out);

	static ShellCommand *create(const std::vector<std::string> &_argv);

};
