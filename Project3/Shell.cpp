
#include <windows.h>
#include <tchar.h> 
#include <stdio.h>
#include <strsafe.h>
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <direct.h>
#include <memory>

#include "Shell.h"
#include "CommandFactory.h"


using namespace std;


int _tmain(int argc, TCHAR *argv[]){
	while (true){
		string inp;
		cout << ">";
		getline(cin, inp);

		cout << inp << endl;

		try {
			shared_ptr<ShellCommand> cmd(createCommand(inp));
			cmd->execute(cin, cout);
		}
		catch (string &err){
			cerr << "Error:" << err << endl;
		}
	}

	return 0; 
}
