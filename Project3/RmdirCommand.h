#pragma once

#include "ShellCommand.h"

class RmdirCommand : public ShellCommand {
protected:
	RmdirCommand(const std::vector<std::string> &_argv) : ShellCommand(_argv) {};
public:
	virtual void execute(std::istream &in, std::ostream &out);

	static ShellCommand *create(const std::vector<std::string> &_argv);
};