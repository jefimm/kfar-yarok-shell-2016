
#pragma once

#include "ShellCommand.h"

class MkdirCommand : public ShellCommand {
public:
	MkdirCommand(const std::string &cmd) : ShellCommand(cmd) {};
	virtual void execute(std::istream &in, std::ostream &out);
};