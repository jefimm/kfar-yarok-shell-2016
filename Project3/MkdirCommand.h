
#pragma once

#include "ShellCommand.h"

class MkdirCommand : public ShellCommand {
protected:
	MkdirCommand(const std::string &cmd) : ShellCommand(cmd) {};
public:
	virtual void execute(std::istream &in, std::ostream &out);

	static ShellCommand *create(const std::string &cmd);

};