
#pragma once

#include "ShellCommand.h"

class MkdirCommand : public ShellCommand {
protected:
	MkdirCommand(const std::vector<std::string> &_argv) : ShellCommand(_argv) {};
public:
	virtual void execute(std::istream &in, std::ostream &out);

	static ShellCommand *create(const std::vector<std::string> &_argv);

};