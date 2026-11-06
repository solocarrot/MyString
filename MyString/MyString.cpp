#include "MyString.h"

MyString::MyString() 
{
	int capacity = 8;
	string = new char[capacity];
	string[0] = '\0';

}

MyString::MyString(const MyString& srcStr)
{
	this->string = new char[srcStr.length()];
	//길이가 8이 아닐떄의 해결
	for (int i = 0; i < length(); i++)
	{
		this->string[i] = srcStr.getChar(i);
	}
}

MyString::~MyString()
{
	delete[] string;
	string = nullptr;
}

int MyString::length() const
{
	int i;
	while (true)
	{
		if (this->string != '\0')
		{
			i++;
			continue;
		}
		else
		{
			return i;
		}
	}
}

void MyString::resize()
{
	if (capacity == length())
	{
		capacity *= 2;
	}
}

char MyString::getChar(int i) const
{
	return string[i];
}

bool MyString::isEmpty() const
{
	if (string[0] == '\0')
	{
		return true;
	}
	else return false;
}

int MyString::getCapatity() const
{
	return capacity;
}

MyString MyString::operator=(const MyString& srcStr)
{
	if (this == &srcStr) return;
	else if (capacity == srcStr.getCapatity())
	{
		for (int i = 0; i < srcStr.length(); i++)
		{
			string[i] = srcStr.getChar(i);
		}
	}
	else
	{
		if (capacity != srcStr.getCapatity())
		{
			this->capacity = srcStr.getCapatity();
			for (int i = 0; i < srcStr.length(); i++)
			{
				string[i] = srcStr.getChar(i);
			}
		}

	}
	return *this;
}

