#pragma once
#include <iostream>
using namespace std;


class MyString
{
public:
	MyString();
	MyString(const MyString&);
	~MyString();

	int length() const;
	bool isEmpty() const;
	int getCapatity() const;
	void resize();
	char getChar(int) const;

	MyString operator=(const MyString&);

private:
	char* string;
	int capacity;
	int size;
};