/***
PROGRAM: CSCI 241 Program 1
PROGRAMMER: Afifah Arif
LOGON ID: XXXXXXXX
DUE DATE: 02/01/2018
FUNCTION: This program tests functions for manipulating C strings.
***/

#include <iostream>
#include <cstring>
#include <cctype>

using std::cin;
using std::cout;
using std::endl;

// Add your function prototypes here
bool equals(const char* str1, const char* str2);
bool equalsIgnoreCase(const char* str1, const char* str2);
int indexOf(const char* str, char ch);
int lastIndexOf(const char* str, char ch);
bool startsWith(const char* str, const char* prefix);
bool endsWith(const char* str, const char* suffix);

int main()
{
	int index;

	// Tests 1a - 1d: Test the equals() function
	cout << "Test 1a: ";
	if (equals("catapult", "catapult"))
	cout << "correct\n";
	else
	cout << "incorrect\n";

	cout << "Test 1b: ";
	if (!equals("catapult", "catamaran"))
	cout << "correct\n";
	else
	cout << "incorrect\n";

	cout << "Test 1c: ";
	if (!equals("cat", "catamaran"))
	cout << "correct\n";
	else
	cout << "incorrect\n";

	cout << "Test 1d: ";
	if (!equals("catapult", "cat"))
	cout << "correct\n";
	else
	cout << "incorrect\n";

	cout << endl;

	// Tests 2a - 2d: Test the equalsIgnoreCase() function
	cout << "Test 2a: ";
	if (equalsIgnoreCase("catapult", "CATAPULT"))
	cout << "correct\n";
	else
	cout << "incorrect\n";

	cout << "Test 2b: ";
	if (!equalsIgnoreCase("catapult", "Catamaran"))
	cout << "correct\n";
	else
	cout << "incorrect\n";

	cout << "Test 2c: ";
	if (!equalsIgnoreCase("Cat", "Catamaran"))
	cout << "correct\n";
	else
	cout << "incorrect\n";

	cout << "Test 2d: ";
	if (!equalsIgnoreCase("Catapult", "Cat"))
	cout << "correct\n";
	else
	cout << "incorrect\n";

	cout << endl;

	// Tests 3a - 3d: Test the indexOf() function
	cout << "Test 3a: ";
	index = indexOf("adamant", 'a');
	if (index == 0)
	cout << "correct\n";
	else
	cout << "incorrect - index returned was " << index << ", not 0\n";

	cout << "Test 3b: ";
	index = indexOf("adamant", 'm');
	if (index == 3)
	cout << "correct\n";
	else
	cout << "incorrect - index returned was " << index << ", not 3\n";

	cout << "Test 3c: ";
	index = indexOf("adamant", 't');
	if (index == 6)
	cout << "correct\n";
	else
	cout << "incorrect - index returned was " << index << ", not 6\n";

	cout << "Test 3d: ";
	index = indexOf("adamant", 'x');
	if (index == -1)
	cout << "correct\n";
	else
	cout << "incorrect - index returned was " << index << ", not -1\n";

	cout << endl;

	// Tests 4a - 4d: Test the lastIndexOf() function
	cout << "Test 4a: ";
	index = lastIndexOf("adamant", 't');
	if (index == 6)
	cout << "correct\n";
	else
	cout << "incorrect - index returned was " << index << ", not 6\n";

	cout << "Test 4b: ";
	index = lastIndexOf("adamant", 'm');
	if (index == 3)
	cout << "correct\n";
	else
	cout << "incorrect - index returned was " << index << ", not 3\n";

	cout << "Test 4c: ";
	index = lastIndexOf("adamant", 'a');
	if (index == 4)
	cout << "correct\n";
	else
	cout << "incorrect - index returned was " << index << ", not 4\n";

	cout << "Test 4d: ";
	index = lastIndexOf("adamant", 'x');
	if (index == -1)
	cout << "correct\n";
	else
	cout << "incorrect - index returned was " << index << ", not -1\n";

	cout << endl;

	// Tests 5a - 5c: Test the startsWith() function
	cout << "Test 5a: ";
	if (startsWith("your house", "your"))
	cout << "correct\n";
	else
	cout << "incorrect\n";

	cout << "Test 5b: ";
	if (!startsWith("my house", "your"))
	cout << "correct\n";
	else
	cout << "incorrect\n";

	cout << "Test 5c: ";
	if (!startsWith("you", "your"))
	cout << "correct\n";
	else
	cout << "incorrect\n";

	cout << endl;

	// Tests 6a - 6c: Test the endsWith() function
	cout << "Test 6a: ";
	if (endsWith("your house", "house"))
	cout << "correct\n";
	else
	cout << "incorrect\n";

	cout << "Test 6b: ";
	if (!endsWith("your mouse", "house"))
	cout << "correct\n";
	else
	cout << "incorrect\n";

	cout << "Test 6c: ";
	if (!endsWith("use", "house"))
	cout << "correct\n";
	else
	cout << "incorrect\n";

	return 0;
}

// Add your function definitions here
bool equals(const char* str1, const char* str2)
{
	if(strcmp(str1, str2) == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool equalsIgnoreCase(const char* str1, const char* str2)
{
	int i;
	for (i=0; str1[i] != '\0' && str2[i] != '\0'; i++)
	{
		if(tolower (str1[i]) != tolower (str2[i]))
		{
			return true;	
		}
		if (str1[i] == '\0' && str2[i] == '\0')
		{
		return false;
		}
	}
}

int indexOf(const char* str, char ch)
{
	int cnt;
	for(cnt=0; cnt < strlen(str); cnt++)
	{
		if(str[cnt] == ch)
		{
			return cnt;
		}
		if(cnt == strlen(str)-1)
		{
		return -1;
		}
	}
}

int lastIndexOf(const char* str, char ch)
{
	int cnt;
	for (cnt = strlen(str)-1; cnt >= 0; cnt --)
	{
		if (str[cnt] == ch)
		{
		return cnt;
		}
	}
	return -1;
}

bool startsWith(const char* str, const char* prefix)
{
	int cnt;
	if (strlen(str) > strlen(prefix))
	{
		for(cnt = 0; prefix[cnt] != '\0'; cnt++)
		{
		if (str[cnt] == prefix[cnt])
		{
		return true;
		}
		}
	}
	else
	{
		return false;
	}
}

bool endsWith(const char* str, const char* suffix)
{
	int cnt;
	int cnt2;
	if(strlen(str) < strlen(suffix))
	{
		for(cnt = 0, cnt2 = 0; suffix[cnt] != '\0', str[cnt] != '\0'; cnt--, cnt2--)
		{
			if (str[cnt] == suffix[cnt])
			{
				return true;
			}
		}
	}
	else
	{
		return false;
	}
}
