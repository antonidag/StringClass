#include "stdafx.h"
#include "String.h"
#include <stdio.h>
#include <assert.h>

String::String()
{
	capcitylen = 10;
	sizelen = 0;
	text = new char[capcitylen];
	fctor = 1;
	invariant();
}

String::String(const String & rhs)
{
	capcitylen = rhs.capcity();
	text = new char[capcitylen];
	sizelen = rhs.size();
	fctor = 1;
	for (size_t i = 0; i < size(); i++)
	{
		text[i] = rhs[i];
	}
	invariant();
}

String::String(const char * cstr)
{
	capcitylen = 10;
	fctor = 1;
	sizelen = countChars(cstr);
	allocate(cstr);
	for (size_t i = 0; i < size(); i++)
	{
		text[i] = cstr[i];
	}
	invariant();
}


String & String::operator=(const String & rhs)
{
	// rhs är större än vår capcity allokera nytt minne.
	if (rhs.size() > capcity()) {
		sizelen = rhs.size();
		capcitylen = rhs.capcity();
		delete[] text;
		text = new char[capcitylen];
	}
	// Sedan kopiera över
	for (size_t i = 0; i < rhs.size(); i++)
	{
		text[i] = rhs[i];
	}
	return *this;
}

char & String::operator[](size_t i)
{
	return text[i];
}

const char & String::operator[](size_t i) const
{
	const char* c = text;

	return c[i];
}

size_t String::size() const
{
	return sizelen;
}

size_t String::capcity() const
{
	return capcitylen;
}

void String::push_back(char c)
{
	if (size() == capcity()) {
		allocate();
	}

	text[size()] = c;
	sizelen++;
}

const char * String::data() const
{
	return text;
}


String::~String()
{
	invariant();
	delete[] text;
}

size_t String::countChars(const char * carry)
{
	size_t len = std::strlen(carry);
	return len;
}

void String::invariant() const
{
	assert(sizelen >= 0);
	assert(capcitylen > 0);
	assert(sizelen <= capcitylen);
}

void String::allocate(const char* cstr)
{
	int cstrlen = countChars(cstr);
	while (cstrlen + 1 > capcity()) {
		fctor++;
		capcitylen = capcitylen * fctor;

	}
	text = new char[capcitylen];
}

void String::allocate()
{
	fctor++;
	capcitylen = capcitylen * fctor;
	char* temp = new char[capcitylen];
	for (size_t i = 0; i < size(); i++)
	{
		temp[i] = text[i];
	}
	delete[] text;
	text = temp;
}

