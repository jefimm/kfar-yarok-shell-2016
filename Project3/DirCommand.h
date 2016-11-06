
#pragma once

#include "ShellCommand.h"

class DirCommand : public ShellCommand {
public:
	DirCommand(const std::string &cmd) : ShellCommand(cmd) {};
	virtual void execute(std::istream &in, std::ostream &out);
};
