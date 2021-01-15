#include<iostream>
#include<cstdio>
using std::FILE;
#include<cstdlib>
using std::strtol;
using namespace std;

int main()
{
	cout << "Enter full path\n";
	char filepath[225];
	cin.getline(filepath, 225);

	FILE* f = nullptr;
	int* numbers = nullptr;

	try
	{
		f = fopen(filepath, "r");

		char line[225];

		size_t const maxlinelength = 225;

		char* read = nullptr;

		if (f)
		{
			read = fgets(line, maxlinelength, f);

		}
		else
		{
			cout << "Could not open file :" << filepath << "\n";
		}

		if (read)
		{
			cout << "first line is:" << endl;
			cout << line;
			char ans;
			cout << "continue? (y/n) ";
			cin >> ans;
			if (ans == 'y')
			{
				char* end;
				int numlines = strtol(line, &end, 10);
				numbers = new int[numlines];
				bool keepgoing = true;
				int linesread = 0;

				while (keepgoing)
				{
					read = fgets(line, maxlinelength, f);
					if (read)
					{
						numbers[linesread] = strtol(line, &end, 10);
						linesread++;

					}
					else
					{
						keepgoing = false;

					}
				}
					cout << linesread + 1 << "lines read.\n";
			}
		}
		if (numbers)
		{
			delete[] numbers;
		}
	}
	catch (...)
	{
		cout << "An error ouccured:";
		if (numbers)
		{
			delete[] numbers;
		}
	}
}