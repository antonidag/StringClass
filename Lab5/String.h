#pragma once
#include <ostream>
class String
{
public:
	String();
	String(const String& rhs);
	String (const char* cstr);
	String& operator = (const String& rhs);
	char& operator [] (size_t i);
	const char& operator [] (size_t i) const;
	size_t size() const;
	size_t capcity() const;
	void push_back(char c);
	friend bool operator == (const String& lhs, const String& rhs);
	friend bool operator != (const String& lhs, const String& rhs);
	friend std::ostream&operator<< (std::ostream& out, const String& rhs);
	const char* data() const;



	~String();

private:
	void invariant() const;
	void allocate(const char* cstr);
	void allocate();
	size_t countChars(const char* carry);
	char* text;
	size_t capcitylen;
	size_t fctor;
	size_t sizelen;
};