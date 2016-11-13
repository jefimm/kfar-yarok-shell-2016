#pragma once

#include "ShellCommand.h"

class RmdirCommand : public ShellCommand {
protected:
	RmdirCommand(const std::string &cmd) : ShellCommand(cmd) {};
public:
	virtual void execute(std::istream &in, std::ostream &out);

	static ShellCommand *create(const std::string &cmd);
};