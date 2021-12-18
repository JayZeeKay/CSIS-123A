/*
ID: 0602306

Jacob Marinas

Guided Practice 9 - Polymorphism

Creating classes from a base class, then using polymorphism to invoke the functions
*/

#include <iostream>

using namespace std;

class Animal
{
    private: 
        int legs;
    public:
        void setLegs(int legs);
        int getLegs();
        Animal() :legs(4) {}
        void talk();
        virtual void speak() = 0;
};

void Animal::speak()
{

}
void Animal::talk()
{
    speak();
}

void Animal::setLegs(int legs)
{
    this->legs = legs;
}

int Animal::getLegs()
{
    return legs;
}

class Cat : public Animal
{
    public:
        void speak();
};

void Cat::speak()
{
    cout << "meow" << endl;
}

class Dog : public Animal
{
    public:
        void speak();
};

void Dog::speak()
{
    cout << "bark" << endl;
}

class Bird : public Animal
{
    public:
        void speak();
};

void Bird::speak()
{
    cout << "quack" << endl;
}

int main()
{
    Cat cat;
    Dog dog;
    Bird bird;

    Animal *an[3];
    an[0] = &cat;
    an[1] = &dog;
    an[2] = &bird;
    
    for (int i = 0; i < 3; i++)
    {
        an[i]->speak();
    }

    return 0;
}