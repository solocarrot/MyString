#pragma once
#include <iostream>
using namespace std;


class MyString
{
public:
	MyString();
	MyString(const MyString&);
	MyString(const char*);
	~MyString();

	int length() const;
	bool isEmpty() const;
	int getCapatity() const;
	void resize();
	char getChar(int) const;
	char& at(int);
	char& operator[](int);
	const char& operator[](int) const;

	void append(char);
	void get(char);

	MyString operator=(const MyString&);
	MyString& operator=(const char*);
	const MyString operator+(const char*);
	const MyString operator+(const MyString&);
	bool operator==(const MyString&);



private:
	char* string;
	int capacity;
	int size;
};

ostream& operator<<(ostream& os, const MyString&);
istream& operator>>(istream& is, MyString&);
istream& getline(istream& is, MyString& str, char delim = '\n');