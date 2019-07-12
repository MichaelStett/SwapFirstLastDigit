#include <iostream>
#include <string>
#include <chrono>
#include <fstream>
using namespace std;

string s;
int l;
unsigned long first, last, sum, digits, nn, a, b;

unsigned long Trivial(unsigned long i)
{
	auto start = std::chrono::system_clock::now();

	s = to_string(i);
	l = s.length();
	swap(s[0], s[l - 1]);

	auto end = std::chrono::system_clock::now();

	return static_cast<unsigned long>((end - start).count());
}

unsigned long Logarithmic(unsigned long i)
{
	auto start = std::chrono::system_clock::now();

	digits = (int)log10(i);
	first = i / pow(10, digits);
	last = i % 10;
	a = first * (pow(10, digits));
	b = i % a;
	i = b / 10;
	nn = last * (pow(10, digits)) + (i * 10) + first;

	auto end = std::chrono::system_clock::now();

	return static_cast<unsigned long>((end - start).count());
}

int main()
{

	ofstream tFile;
	tFile.open("tFile.txt");

	ofstream lFile;
	lFile.open("lFile.txt");

	if (tFile.is_open() && lFile.is_open())
	{
		for (int i = 0; i < 0xff; i++)
		{
			tFile << to_string(Trivial(i)) << "ms\n";
			lFile << to_string(Logarithmic(i)) << "ms\n";
		}
	}

	tFile.close();
	lFile.close();

	return 0;
}