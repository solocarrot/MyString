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
	char& at(int);
	char& operator[](int);
	const char& operator[](int) const;

	void setChar(int , char);
	void get(char);





	MyString operator=(const MyString&);

private:
	char* string;
	int capacity;
	int size;
};

ostream& operator<<(ostream& os, const MyString& str);
istream& operator>>(istream& is, MyString& str);
istream& getline(istream& is, MyString& str, char delim = '\n');