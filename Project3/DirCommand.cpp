#include <windows.h>
#include <vector>
#include <string>
#include <strsafe.h>

#include "DirCommand.h"
#include "Shell.h"

using namespace std;

class FileInfo{
private:
	string name;
	LARGE_INTEGER size;
public:
	FileInfo(const string& dirname) : name(dirname) { size.QuadPart = -1L; };
	FileInfo(const string& filename, LARGE_INTEGER filesize) : name(filename), size(filesize) {};

	inline LARGE_INTEGER getsize() const { return size; }
	inline const string& getname() const { return name; }

	inline bool isDir() const { return size.QuadPart == -1L; }
};


/*
cin
cout
cerr
*/
static void get_directory_listing(const string &dir, vector<FileInfo>& out){
	WIN32_FIND_DATA ffd;
	LARGE_INTEGER filesize;
	TCHAR szDir[MAX_PATH];
	size_t length_of_arg;
	HANDLE hFind = INVALID_HANDLE_VALUE;
	DWORD dwError = 0;

	// Check that the input path plus 3 is not longer than MAX_PATH.
	// Three characters are for the "\*" plus NULL appended below.

	if (dir.size() > (MAX_PATH - 3))
	{
		throw string(TEXT("\nDirectory path is too long.\n"));
	}

	// _tprintf(TEXT("\nTarget directory is %s\n\n"), argv[1]);

	// Prepare string for use with FindFile functions.  First, copy the
	// string to a buffer, then append '\*' to the directory name.

	StringCchCopy(szDir, MAX_PATH, dir.c_str());
	StringCchCat(szDir, MAX_PATH, TEXT("\\*"));

	// Find the first file in the directory.

	hFind = FindFirstFile(szDir, &ffd);

	if (INVALID_HANDLE_VALUE == hFind)
	{
		throw string("FindFirstFile");
	}

	// List all the files in the directory with some info about them.

	do
	{
		// & - bitwise
		// && - logical (true/false)
		// CHAR *ptr = ffd.cFileName();
		string filename(ffd.cFileName);
		if (ffd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
		{
			out.push_back(FileInfo(filename));
			// _tprintf(TEXT("  %s   <DIR>\n"), ffd.cFileName);
		}
		else
		{
			filesize.LowPart = ffd.nFileSizeLow;
			filesize.HighPart = ffd.nFileSizeHigh;
			out.push_back(FileInfo(filename, filesize));

			// _tprintf(TEXT("  %s   %ld bytes\n"), ffd.cFileName, filesize.QuadPart);
		}
	} while (FindNextFile(hFind, &ffd) != 0);

	dwError = GetLastError();
	if (dwError != ERROR_NO_MORE_FILES)
	{
		throw string(TEXT("FindFirstFile"));
	}

	FindClose(hFind);
	return;
}


void DirCommand::execute(std::istream &in, std::ostream &out){
	vector<string> tokens;
	tokenize(command, tokens, " ", true);

	vector<FileInfo> list;
	get_directory_listing(tokens[1], list);
	for (auto it = list.begin(); it != list.end(); ++it){
		if (it->isDir()){
			out << "DIR " << it->getname() << endl;
		}
		else {
			out << it->getsize().QuadPart << " " << it->getname() << endl;
		}
	}
};