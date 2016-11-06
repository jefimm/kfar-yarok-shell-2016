#pragma once

#include "ShellCommand.h"

class RmdirCommand : public ShellCommand {
public:
	RmdirCommand(const std::string &cmd) : ShellCommand(cmd) {};
	virtual void execute(std::istream &in, std::ostream &out);
};