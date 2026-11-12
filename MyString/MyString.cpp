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

void MyString::upSize()
{
	size++;
}

int MyString::getSize()
{
	return size;
}

istream& operator>>(istream& is, MyString& str)
{
	
	char c = is.get();
	while (c == ' ')
	{
		c = is.get();
	}


	for (;c != '\n';c = is.get())
	{
		str.append(c);
	}
	return is;
}

void MyString::append(char c)
{
	if (size + 1 == capacity)
	{
		resize();
	}
	string[size] = c;
	size++;
	string[size + 1] = '\0';
	return;
}

istream& getline(istream& is, MyString& str, char delim = '\n')
{
	char c = is.get();
	while (c != delim)
	{
		str.append(c);
		c = is.get();
	}
	return is;
}

MyString::MyString(const char* cstr2nd)
{
	for (int i = 0; cstr2nd[i] != '\0'; i++)
	{
		append(cstr2nd[i]);
	}
}

MyString& MyString::operator=(const char* cstr2nd)
{
	for (int i = 0; cstr2nd[i] != '\0'; i++)
	{
		append(cstr2nd[i]);
	}
}

const MyString MyString::operator+(const char* cstr2nd)
{
	MyString resultString;
	//임시객체이기때문에 함수끝날때 사라지니까 깊은복사를해야된다?
	//append에서 resize를 구현해둬서 크기에대한 고민을안해도된다.

	for (int i = 0; i < this->size; i++)
	{
		resultString.append(string[i]);
	}

	for (int i = 0; cstr2nd[i] != '\0'; i++)
	{
		resultString.append(cstr2nd[i]);
	}

	return resultString;
}

const MyString MyString::operator+(const MyString& str2nd)
{
	MyString resultString;

	for (int i = 0; i < this->size; i++)
	{
		resultString.append(this->string[i]);
	}

	for (int i = 0; i < str2nd.length(); i++)
	{
		resultString.append(str2nd.getChar(i));
	}

	return resultString;
}

bool MyString::operator==(const MyString& str)
{
	if (this->size != str.length())
	{
		return false;
	}
	else
	{
		int i = 0;
		while (i < this->size)
		{
			if (this->string[i] != str.getChar(i)) return false;
			i++;
		}
	}
	return true;
}