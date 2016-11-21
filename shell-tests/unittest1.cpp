#include "stdafx.h"
#include "CppUnitTest.h"
#include "DirCommand.h"

using namespace std;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace shelltests
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			vector<string> args = {
				string("dir"),
				string("c:\\")
			};
			auto obj = DirCommand::create(args);

			stringstream input;
			stringstream output;

			obj->execute(input, output);

			string data = output.str();
			
			Assert::IsTrue(data.size() > 0);

			delete obj;

		}

	};
}