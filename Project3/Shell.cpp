
#include <iostream>
#include <string>
#include <vector>
#include <list>

#include "Shell.h"



using namespace std;
/*
cin
cout
cerr
*/
void print_directory_listing(){

}

int main(int argc,  char** argv){

	string inp;

	getline(cin, inp);

	// dir 
	// dir directory
	vector<string> tokens;
	tokenize(inp, tokens, " ", true);

	if (tokens.size()>=1){
		if (tokens[0] == "dir"){
			print_directory_listing();
		}
	}

	return 0; 
}
