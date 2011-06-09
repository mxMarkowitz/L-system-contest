#include <iostream>
#include <string>
#include <map>
#include <Windows.h>
using namespace std;

map<char, string> rules;


void setRule(char &in, string &out)
{
	rules[in]=out;
}


void main()
{
	LARGE_INTEGER frequency;
	LARGE_INTEGER t1, t2;
	double elapsedTime;

	char x;
	string y;
	char z;
	bool initCheck = false;
	int numGen;
	string initStr;
	string nextStr;
	while (initCheck == false)
	{
		cout << "Please input a key = " << endl;
		cin >> x;
		cout << "Please input a value = " << endl;
		cin >> y;
		setRule(x, y);
		cout << "Done?(y/n)" << endl;
		cin >> z;
		if (z == 'y')
		{
			initCheck = true;
		}
		else 
		{
			initCheck = false;
		}
	}
	cout << "Please input number of generations: " << endl;
	cin >> numGen; 

	cout << "Initial String?" << endl;
	cin >> initStr;


	QueryPerformanceFrequency(&frequency);
	QueryPerformanceCounter(&t1);
	for ( int i = 0; i < numGen; i++)
	{ 
		//nextStr.reserve(2 * (initStr.length()));
		for (int j = 0; j < initStr.length(); j++)
		{
			nextStr.append(rules.find(initStr[j])->second);
		}

		initStr.swap(nextStr);
		nextStr.clear();
	}
	QueryPerformanceCounter(&t2);
	//cout << initStr << endl;

	cout << "Total Time: " << ((t2.QuadPart - t1.QuadPart) * 1000.0 / frequency.QuadPart) << endl;
	
}