#include "MyString.h"

MyString::MyString() 
{
	int capacity = 8;
	string = new char[capacity];
	string[0] = '\0';

}

MyString::MyString(const MyString& srcStr)
{
	string = new char[srcStr.length() + 1];
	//길이가 8이 아닐떄의 해결
	for (int i = 0; i < srcStr.length() - 1; i++)
	{
		this->string[i] = srcStr.getChar(i);
	}
	string[srcStr.length() + 1] = '\0';
}

MyString::~MyString()
{
	delete[] string;
	string = nullptr;
}

int MyString::length() const
{
	int i = 0;
	while (true)
	{
		if (this->string[i] != '\0')
		{
			i++;
			continue;
		}
		else
		{
			break;
		}
	}
	return i;
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


char& MyString::at(int pos)
{
	return string[pos];
}

char& MyString::operator[](int pos)
{
	return string[pos];
}

const char& MyString::operator[](int pos) const
{
	return string[pos];
}

ostream& operator<<(ostream& os, const MyString& str)
{
	for (int i = 0; i < str.length(); i++)
	{
		os << str.getChar(i);
	}

	return os;
}

istream& operator>>(istream& is, MyString& str)
{

	char c;
	int i = 0;
	while (true)
	{
		if (i == str.getCapatity())
		{
			str.resize();
		}
		str.get(c);
		str.setChar(i,c);
		i++;
	}
}

void MyString::setChar(int i , char c)
{
	string[i] = c;
	return;
}

char MyString::get(char c)
{
	if (c == '\n')
	{
		return 
	}
	else
	{
		return c;
	}
}
