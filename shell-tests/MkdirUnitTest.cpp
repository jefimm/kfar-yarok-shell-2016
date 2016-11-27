#include "stdafx.h"
#include <cstdio>
#include <memory>
#include <time.h>  
#include <sys/types.h>  
#include <sys/stat.h>  
#include <stdio.h>  
#include <errno.h> 
#include <direct.h>
#include "CppUnitTest.h"
#include "MkdirCommand.h"

using namespace std;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;


/*
https://msdn.microsoft.com/en-us/library/14h5k7ff.aspx
*/
namespace shelltests
{
	TEST_CLASS(MkdirUnitTest)
	{
	public:
		
		TEST_METHOD(MkdirTest1)
		{
			char tempname[256] = { 0 };
			tmpnam_s(tempname, sizeof(tempname));
			struct _stat buf;

			vector<string> args = {
				string("mkdir"),
				tempname
			};
			shared_ptr<ShellCommand> obj(MkdirCommand::create(args));
			stringstream input;
			stringstream output;

			obj->execute(input, output);

			int result = _stat(tempname, &buf);

			Assert::IsTrue(result == 0);
			Assert::IsTrue(buf.st_mode & _S_IFDIR);

			_rmdir(tempname);

		}

		TEST_METHOD(MkdirTest2)
		{
			char tempname[256*2] = { 0 };
			tmpnam_s(tempname, sizeof(tempname));
			strcat(tempname, "\\kuku");

			vector<string> args = {
				string("mkdir"),
				tempname
			};
			shared_ptr<ShellCommand> obj(MkdirCommand::create(args));
			stringstream input;
			stringstream output;

			bool exception = false;
			try {
				obj->execute(input, output);
			}
			catch (const string &s){
				exception = true;
			}
			
			Assert::IsTrue(exception);

		}
	};
}