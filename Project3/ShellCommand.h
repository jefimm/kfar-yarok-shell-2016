#include <iostream>
#include <vector>

#pragma once

class ShellCommand{
protected:
	const std::vector<std::string> argv;
	ShellCommand(const std::vector<std::string> &_argv) : argv(_argv) {};

	static void throwError(const std::string &prefix);
public:
	virtual void execute(std::istream &in, std::ostream &out) = 0;
};
