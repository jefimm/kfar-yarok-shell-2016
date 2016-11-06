
#include <windows.h>
#include <tchar.h> 
#include <stdio.h>
#include <strsafe.h>
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <direct.h>

#include "Shell.h"

using namespace std;


int _tmain(int argc, TCHAR *argv[]){
	while (true){
		string inp;
		cout << ">";
		getline(cin, inp);

		cout << inp << endl;
		// dir 
		// dir directory
		vector<string> tokens;
		tokenize(inp, tokens, " ", true);

		if (tokens.size() >= 1){
			if (tokens[0] == "dir"){
				
			}
			if (tokens[0] == "mkdir")
			{

			}
			if (tokens[0] == "rmdir")
			{
				
			}
		}
		

	}

	return 0; 
}
