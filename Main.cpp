/**
*
* Solution to homework task
* Data Structures Course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2016/2017
*
* @author Evgeni Dimov
* @idnumber 45137
* @task 2
* @compiler VC
*
*/
#include<iostream>
#include"ReadFromFile.h"
#include"CompressToFile.h"
#include<string>
#include<vector>
using namespace std;
/*
void getDir(const char* d, vector<string>& f)
{
	FILE* pipe = NULL;
	string pCmd = "dir /B /S " + string(d);
	char buf[256];

	if (NULL == (pipe = _popen(pCmd.c_str(), "rt")))
	{
		cout << "Shit" << endl;
		return;
	}

	while (!feof(pipe))
	{
		if (fgets(buf, 256, pipe) != NULL)
		{
			f.push_back(string(buf));
		}

	}
	_pclose(pipe);

}
*/

int main(int argc,char **argv)
{
	
	/*
	char dir[256];
	std::cin.getline(dir, 256);

	vector<string> files;
	getDir(dir, files);
	char* in = nullptr;
	char* out = new char[30];
	char* result = new char[30];
	int i = files.size();
	while (!files.empty())
	{
		
		in = new char[files.back().size()];
		std::copy(files.back().begin(), files.back().end(), in);
		in[files.back().size()-1] = '\0';

		sprintf(out, "write_%d.bin", i);
		sprintf(result, "result_%d.txt", i);

		ReadFromFile(in);
		WriteToFile(in, out);
		deCompress(out, result);

		files.pop_back();
		--i;
	}
	*/

	char* out = {"write.bin"};
	char* result = { "result.txt" };
	char* in = { "text.txt" };
	
	ReadFromFile(in);
	WriteToFile(in,out);
	deCompress(out,result);
	std::cout << "FINISHED!" << std::endl;

	return 0;
}