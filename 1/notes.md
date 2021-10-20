# Unit 1 - Introduction to OOP

## Strings

* C++ language was born out of C, low level language that had very little keywords
    * The idea of string in C is to create an array of characters
    * An array of characters in C++ is CString and there are built in functions
        * strlen, strcpy, strcmp, strcat

```cpp
#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s;
    cin >> s;
    cout << s << endl;

    return 0;
}
```
* Can be used like a primitive

### Accessing Characters

* String class in C++ can be used like an array

```cpp
string str10 = "abcdefghi";
char ch = str10[3];
cout << ch << endl; // 'd'
str10[5] = 'X';
```

* Trying to access elements outside the array causes a  `string subscript outside of range` error

### Overloaded String Operators

* The assignment operator may be used in several ways

```cpp
string string_one = "Hello";
string string_two;
string_two = string_one;
```

* Assigning a single character (char) to a string object

```cpp
string string_four; char ch = 'A';
string_four = ch;
string_four = 'Z';
```

* The addtion operator concatenates:

* Two string objects

```cpp
string str1 = "Hello ";
string str2 = "there";
string str3 = str1 + str2; // "Hello there"
```

* A string object and a character literal

```cpp
string str1 = "Hello ";
string str4 = str1 + "there";
``` 

* A string object and a single character

```cpp
string str5 = "The End";
string str6 = str5 + '!'; // "The End!"
```

* The shortcut (+=) operator

```cpp
string str1 = "Hello ";
str1 += "there";
```

* Relational operators return a boolean indicating whether the specified relationship exists between the two operands

* Stream insertion operator

```cpp
string str1 = "Hello there";
cout << str1 << endl;
```

* Stream extraction operator

```cpp 
string str1;
cin >> str1;
```

* Assigning a character to a string doesn't work as expect, so you must use a special form

```cpp
string str6 = 'A'; // Incorrect
string str7 ('A'); // Also incorrect
```

```cpp
string str7 (1,'A'); // Correct
```

* Substring of another string object

```cpp
string str8 = "ABCDEFGHIJKL";

/*
Initialize str9 as "CDEFG"
starting at character 2 ('C') with a length of 5
(or the rest of the string, if shorter)
*/
string str9 (str8,2,5);
```

### String functions

```cpp
string str = "Hello";
string::size_type len;
len = str.length(); // len == 5
len = str.size(); // len == 5
```

* Returns an unsigned integer type

* Sometimes it is necessary to convert a string object into a character array (C-style string)

```cpp
string filename;

cout << "Enter file name: ";
cin >> filename;

ofstream outfile (filename.c_str());
outfile << "Data" << endl;
```

* Other functions
    * string& insert(size_type pos, const string& str);
    * string& erase(size_type pos, size_type n);
    * string& replace(size_type pos, size_type n, const string& str);
    size_type find (const string& str, size_type pos);
        * Search for the first occurance of the substring str in the current string, starting at position pos
            * If found, returns the position of the first character
            * If not, returns a special value called `string::npos`
        * rfind does the same thing but last occurance 
    * string substr (size_type pos, size_type n);


### Getting Strings from the Keyboard

* The cin function works really well for single words, but it stops processing when it sees a white space
    * To get a complete line of text, use getline function

```cpp
istream& getline (istream& is, string& str, char delim = '\n')
```

* Stops when one of the following occurs
    * An end-of-line condition occurs on the input stream
    * When the maximum number of characters that can fit into a string have been read
    * When a character read from the string is equal to the specified delimiter (newline is the default delimiter)

```cpp
int main()
{
    string str;

    getline(cin, str, '?');
    cout << str << endl;
  
    return 0;

}
```

### The stringstream Class

* Provides an interface that allows you to treat strings as if they were input and output streams
    * First must include `<sstream>`

* You can use the stream insertion operator

```cpp
double d = 3.145;
stringstream ss;
ss << d
```

* Once assigned to the stringstream class you can use the str function to turn it into a string

* If you need to set precision on how your number will be displayed, use the precision function

```cpp
#include <iostream>
#include <sstream>

using namespace std;

int main()
{
	double d;
	
	stringstream ss;
	cout << "Enter a number and I will convert it to a string" << endl;
	cin >> d;

	ss.precision(4);
	ss << d;

	string s = ss.str();
	cout << s << endl;

	return 0;
}
```

* Rounding takes place before the truncation of the numbers happen
* Use clear function to clear instance of stringstream

### Converting Number Types

* You can convert a number to decimal, octal, hex and output it

```cpp
int main()
{
    int x = 32;
    cout << hex << x << endl;
    cout << oct << x << endl;
    cout << dec << x << endl;

    return 0;
}
```

* You can do the same thing with the stringstream class

```cpp
int x = 32;
stringstream ss;

ss << hex << x;
string str = ss.str();
```

### Converting Strings to Numbers

```cpp
char str[] = "3.145";
double num = atof(str);
```

* Use c_str function to turn it into "C-style string"

```cpp
string str = "3.145";
double num = atof(str.c_str());
```

* There are updated functions that do work with CString
    * stoi - string to integer
    * stod - string to double

