#include <iostream>

#include <sstream>
#include <Windows.h>


class Utf8buf : public std::stringbuf
{
public:
	int sync()
	{
		fputs(str().c_str(), stdout);
		str("");
		return 0;
	}
};


int main()
{
	SetConsoleOutputCP(CP_UTF8);
	setvbuf(stdout, nullptr, _IONBF, 0);
	Utf8buf utf8buf;
	std::cout.rdbuf(&utf8buf);

	std::cout << "Привет, мир!" << std::endl;
	return 0;
}
