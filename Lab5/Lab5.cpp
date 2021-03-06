// Lab5.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "String.h"
#include <iostream>
bool operator==(const String & lhs, const String & rhs)
{
	for (size_t i = 0; i < lhs.size(); i++)
	{
		if (lhs[i] != rhs[i]) {
			return false;
		}
	}
	return true;
}
bool operator!=(const String & lhs, const String & rhs)
{
	for (size_t i = 0; i < lhs.size(); i++)
	{
		if (lhs[i] != rhs[i]) {
			return true;
		}
	}
	return false;
}

std::ostream & operator<<(std::ostream & out, const String & rhs)
{
	int sizeRhs = rhs.size();
	for (size_t i = 0; i < sizeRhs; i++)
	{
		out << rhs[i];
	}
	return out;
}
int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	String s("hej");
	String b("hejdaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
	String c;
	String d("Nusa");
	String e(d);


	c.push_back('b');

	std::cout << "50 push_back on string d\n";
	for (size_t i = 0; i < 50; i++)
	{
		d.push_back('c');
	}


	s = b;
	c = s;

	if (s == b) {
		std::cout << "\ns and b are equal";
	}
	if (c != d) {
		std::cout << "\nc and d are not equal";
	}

	std::cout << "\nS = " << s;
	std::cout << "\nB = " << b;
	std::cout << "\nC = " << c;
	std::cout << "\nD = " << d;
	std::cout << "\nE = " << c;
	c = d;

	if (c == d) {
		std::cout << "\nc and d are now equal";
	}
	std::cout << "\nC = " << c;

	std::cin.get();
    return 0;
}

