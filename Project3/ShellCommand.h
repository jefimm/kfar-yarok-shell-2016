#include <iostream>

#pragma once

class ShellCommand{
protected:
	const std::string command;
	ShellCommand(const std::string &cmd) : command(cmd) {};
public:
	virtual void execute(std::istream &in, std::ostream &out) = 0;
};
