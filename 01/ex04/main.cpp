#include <cstdlib>
#include <iostream>
#include <fstream>

static bool setFileContent(std::string fileName, std::string &content)
{
	std::ifstream	fin;
	std::string 	line;
	bool			fail;

	content.clear();
	fail = true;
	fin.open(fileName.c_str());
	if (!fin.fail())
	{
		while (std::getline(fin, line))
			content.append(line).append("\n");
		fail = false;
	}
	else
		perror(fileName.c_str());
	fin.close();
	return (!fail);
}

static void myReplace(std::string &str, std::string s1, std::string s2)
{
	size_t lastPos;
	std::string left;
	size_t		s1Length;

	s1Length = s1.length();
	while ((lastPos = str.find(s1, lastPos)) != str.npos)
	{
		left = str.substr(0, lastPos).append(s2);
		left += str.substr(lastPos + s1Length);
		str = left;
		lastPos += s1Length;
	}
}

static bool saveFile(std::string fileName, std::string &content)
{
	std::ofstream fout;

	fout.open(fileName.append(".replace").c_str());
	if (fout.fail())
	{
		fout.close();
		return (false);
	}
	fout << content;
	fout.close();
	return (true);
}

int main(int argc, char *argv[])
{
	std::string rContent;

	if (argc != 4)
	{
		std::cout << "Missing params. Usage: ./main filename s1 s2" << std::endl;
		return (EXIT_FAILURE);
	}
	if (!setFileContent(argv[1], rContent))
		return (EXIT_FAILURE);
	myReplace(rContent, argv[2], argv[3]);
	if (!saveFile(argv[1], rContent))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
