#include "ShellCommand.h"

void ShellCommand::throwError(const std::string &prefix){
	char error_buffer[256];
	strerror_s(error_buffer, sizeof(error_buffer), errno);
	throw  prefix + " " + error_buffer;
}