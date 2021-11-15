# Unit 8 - Static Variables

* Local variables are created on the stack within the body of a function or block. Global is created on the heap

```cpp
#include  <iostream>

using namespace std;

void toggle(void);

int main ()
{
   for(int i = 0; i < 5; i++)
      toggle();

   return 0;
}
void toggle(void)
{
   bool flag = false;
  
   flag = !flag;
  
   if(flag == true)
      cout << "ON" << endl;
   else
      cout << "OFF" << endl;
} 
```

* Only "ON" gets outputted

* In order for the variable to maintain its value throughout all the calls to the function, the variable needs to be made static
    * Gets created on the heap and initalized one time

```cpp
#include  <iostream>

using namespace std;

void toggle(void);

int main ()
{
   for(int i = 0; i < 5; i++)
      toggle();

   return 0;
}
void toggle(void)
{
   static bool flag = false;
  
   flag = !flag;
  
   if(flag == true)
      cout << "ON" << endl;
   else
      cout << "OFF" << endl;
} 
```

## Static Class Variables

* Shared among instances of the class
    * Different from objects created from the class, where each object has their own instances of class variables

```cpp
class Rectangle
{
private:	
	int length;
	int width;

public:
        static int count;    // Create the static count variable. Keeps track of instances. 
	Rectangle(int length, int width);
	Rectangle() :length(0), width(0) {}
        ~Rectangle(); // Destructor
	int area();

	void setValues(int length, int width);  //Mutator
	int getLength();   //Accessor
	int getWidth();    //Accessor

	Rectangle add(const Rectangle &r);
	Rectangle operator +(const Rectangle &r);
};
```

* Once you define a static data member, it exists even though no objects of its class exist
    * Needs to be declared in global scope
    * The scope resolution operator tells what class it belongs to

```cpp
int Rectangle::count = 0;   //Initialize the static variable

Rectangle::Rectangle(int length, int width)
{
	this->setValues(length, width);
	Rectangle::count++;  //Incrment the counter
}
Rectangle::~Rectangle()
{
	Rectangle::count--; // Decrement the counter
}
```

## Static Member Functions

* Works the same way static variables do
    * Since they don't belong to a class, you cannot use the keyword `this`

```cpp
class Rectangle
{
private:
	static int count;  // static count variable
	int length;
	int width;

public:
	static void printCount();  // Accessor for static count

	Rectangle(int length, int width);
	Rectangle() :length(0), width(0) {}
	~Rectangle();
	int area();

	void setValues(int length, int width);  //Mutator
	int getLength();   //Accessor
	int getWidth();    //Accessor

	Rectangle add(const Rectangle &r);
	Rectangle operator +(const Rectangle &r);
};
```

```cpp
int Rectangle::count = 0;   //Initialize the static variable

Rectangle::Rectangle(int length, int width)
{
	this->setValues(length, width);
	Rectangle::count++;  //Incrment the counter
}
Rectangle::~Rectangle()
{
	Rectangle::count--; // Decrement the counter
}
// Static accessor function for static variable
void Rectangle::printCount()
{
	cout << "There are " << Rectangle::count << " Instances" << endl;
}
```

* A simple call to the function without the object

```cpp
int main()
{	
	
	Rectangle *r1 = new Rectangle(4, 5);
	Rectangle *r2 = new Rectangle(6, 7);

	Rectangle::printCount();
	delete r1;
	Rectangle::printCount();
	
	return 0;
}
```

# Design Patterns

* A way or an approach to solving common software design problems
    * The book Design Patterns: Elements of Resuable Object Oriented Sotware
        * 23 patterns introduced 
    * Design patterns can be classified as
        1. Creational Patterns
        2. Structural Patterns
        3. Behavioral Patterns

## The Singleton Design Pattern

* Where you want to use an object without having to place it in global scope
    * Imagine a menu class that has funcitonality where you want it to be accessed from many other functions

```cpp
struct menuItem
{
	string descript;
	void(*func)();
};
class Menu
{
private:
	vector mi;
	int count;
	void runSelection();
	static Menu *pInstance;
public:
	Menu();
	void addMenu(string Descript, void(*f)());
	void runMenu();
	void waitKey();
	static Menu *Instance();
};
```

```cpp
Menu m; // In global scope so functions can have access
int main()
{
   m.addMenu("1. Function 1", func1);
   m.addMenu("2. Function 2", func2);
   m.addMenu("4. Exit", Exit);
   m.runMenu();
   return 0;
 }
 void func1()
 {
    cout << "Hello from function 1" << endl;
    m.waitKey();
 }
void func2()
{
    cout << "Hello from function 2 " << endl;
    m.waitKey();
}
void Exit()
{
    cout << "Goodbye" << endl;
    exit(0);
}
```

* We create an instance of the menu in global scope
    * Not good coding practice

* Singleton design pattern uses a private static pointer

```cpp
class Menu
{
private:
	vector mi;
	int count;
	void runSelection();
	static Menu *pInstance;//static instance pointer
public:
	Menu();
	void addMenu(string Descript, void(*f)());
	void runMenu();
	void waitKey();
	static Menu *Instance();
};
```

```cpp
//Initialize the static instance pointer
Menu *Menu::pInstance = NULL; 
//Create the accessor function which will return the instance 
Menu *Menu::Instance()
{
    if(pInstance == NULL)
       pInstance = new Menu;

    return pInstance;
}
```

```cpp
//Menu removed from global scope
{
   Menu *m = Menu::Instance();   // First time called new will create a new instance of the class
   m->addMenu("1. Function 1", func1);
   m->addMenu("2. Function 2", func2);
   m->addMenu("4. Exit", Exit);
   m->runMenu();
   return 0;
 }
 void func1()
 {
    cout << "Hello from function 1" << endl;
     Menu *m = Menu::Instance(); // Instance pointer is returned
    m->waitKey();
 }
void func2()
{
    cout << "Hello from function 2 " << endl;
    Menu *m = Menu::Instance(); // Instance pointer is returned
    m->waitKey();
}
void Exit()
{
    cout << "Goodbye" << endl;
     Menu *m = Menu::Instance(); // Instance pointer is returned 
    exit(0);
}
```

## Factory Design Pattern

* A static member function that is used to create an instance of an object 
    * Localize the creation of the object and prevent disturbance of the system when a new type is introduced

```cpp
class Rectangle
{
private:
	static int count;  // static count variable
	int length;
	int width;

public:
	static void printCount();  // Accessor for static count

	Rectangle(int length, int width);
	Rectangle() :length(0), width(0) {}
	~Rectangle();
	int area();

	void setValues(int length, int width);  //Mutator
	int getLength();   //Accessor
	int getWidth();    //Accessor

	Rectangle add(const Rectangle &r);
	Rectangle operator +(const Rectangle &r);

	// Factory method to create a Rectangle
	static Rectangle *create(int length, int width);
}; 
```

```cpp

//Factory method creates a Rectangle
Rectangle *Rectangle::create(int length, int width)
{
	return new Rectangle(length, width);
}
```

```cpp
int main()
{	
	
	Rectangle *r1 = Rectangle::create(4, 5);
	Rectangle *r2 = Rectangle::create(6, 7);

	Rectangle::printCount();
	delete r1;
	Rectangle::printCount();
	
	return 0;
}
```

## Other Popular Design Patterns

* Observer
* Template
* Chain of Responsibility
* Command
* Adapter 
* Visitor
* Facade
* Builder
* Composite
* Decorator

# Namespaces

* Allows you to group a set of global classes, objects, and/or functions under a name
    * They serve to split the global scope into sub-scopes

```cpp
namespace identifier
{
    namespace-body 
} 
```

* namespace body is the set of classes, objects, and functions that are included in the namespace

```cpp
namespace general
{ 
     int a, b;
} 
```

* In order to use the variables from outside the namespace, you must use the scope resolution operator

```cpp
general::a
general::b
```

* Useful when there are two variables of the same name from different namespaces 

```cpp
#include  <iostream>
using namespace std;

namespace first
{
   int var = 5;
}

namespace second
{
   double var = 3.1416;
} 


int main ()
{
   cout << first::var << endl;
   cout << second::var << endl;
   return 0;
} 
```

## Using namespace

```cpp
using namespace identifier ; 
```

* The using directive allows the objects and functions of that namespace to be used as if they were global scope

```cpp#include <iostream>
using namespace std;
namespace first
{
   int var = 5;
}
namespace second
{
   double var = 3.1416;
}
int main ()
{
   using namespace second;
   cout << var << endl;
   cout << (var*2) << endl;
   return 0;
}
```

* One common mistake is that people believe that everything needs to be in one file in order to wrap the code in the namespace
    * You only need to wrap your code inside a namespace declaration in each file

```cpp
namespace glenn  //Namespace declaration
{
	class Rectangle
	{
	private:
		int length;
		int width;

	public:
		
		Rectangle(int length, int width);
		Rectangle();
		~Rectangle();
		int area();

		void setValues(int length, int width);  //Mutator
		int getLength();   //Accessor
		int getWidth();    //Accessor

		Rectangle add(const Rectangle &r);
		Rectangle operator +(const Rectangle &r);		
	};
```

```cpp
namespace glenn  //namespace declaration
{
	Rectangle::Rectangle()
	{
		Rectangle(1, 1);
	}
	Rectangle::Rectangle(int length, int width)
	{
		this->setValues(length, width);
	}	
	Rectangle::~Rectangle()
	{		
	}
	void Rectangle::setValues(int length, int width)
	{
		this->length = length;
		this->width = width;
	}
	int Rectangle::getLength()
	{
		return this->length;
	}
	int Rectangle::getWidth()
	{
		return this->width;
	}
	Rectangle Rectangle::add(const Rectangle &r)
	{
		Rectangle tmp(this->getLength() + this->getLength(),
			this->getWidth() + this->getWidth());
		return tmp;
	}
	Rectangle Rectangle::operator +(const Rectangle &r)
	{
		return this->add(r);
	}
	int Rectangle::area()
	{
		return this->getLength() * this->getWidth();
	}
} // End namespace block
```

* Putting the using namespace declaration inside a header file should be avoided, since every use of the header file will include that particular namespace. Do it this way:

```cpp
using std::string;
using std::endl;
using glenn::rectangle
```

## Alias Definition

* You can define an alias, allowing you to specify a nemspace by a different name

```cpp
namespace new_name = current_name;
```

```cpp
#include <iostream>

//Give std an alias
namespace glenn = std;

int main ()
{
   glenn::cout << "Hello from Glenn" << glenn::endl;
   return 0;
}  
```

## namespace std

* As defined in the ANSI C++ standard, all the classes, objects, and functions of the standard C++ library are defined within namespace std
    * The use of std is a somewhat recent addition, only as recent as the ANSI standard itself (1997). Many older compilers do not comply with this rule
    * Almost all compilers allow the use of the traditional header files and you can use them as you would with namespaces
    * The standard has redesigned the libraries with the templates feature and declared all functions under the namespace std

```cpp
// ANSI-C++ compliant hello world
#include <iostream>

int main ()
{
   std::cout << "Hello world in ANSI-C++\n";
   return 0;
} 
```

```cpp
// ANSI-C++ compliant hello world (II)
#include <iostream>
using namespace std;

int main ()
{
   cout << "Hello world in ANSI-C++\n";
   return 0;
}
```


