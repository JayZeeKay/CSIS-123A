#include <iostream>
#include <string>
#include "Random.h"
#include <ctime>

using namespace std;

Random::Random()
    //:Random(0, RAND_MAX)
{
    // "delegating constructors are permitted only in C++11" so reusing code here so it works
    numberList.assign(250, 0);
    srand(static_cast<unsigned int>(time(0)));
    setRange(min, max);
}

Random::Random(double min, double max)
{
    // Clear vector
    numberList.assign(250, 0);
    // Use time to seed
    srand(static_cast<unsigned int>(time(0)));
    // setRange will also fill the vect
    setRange(min, max);
}

Random::Random(int seed)
{
    numberList.assign(250, 0);
    srand(seed);
    // Need to include fillVect since setRange is not used, no fill vect
    fillVect();
}

int Random::nextInt()
{
    // Gets the next number, and ++ increments so that next time the function is called, it gets the next number after
    return (int) numberList[count++];
}

double Random::nextDbl()
{
    return numberList[count++];
}

void Random::setRange(double min, double max)
{
    if (max < min)
    {
        cout << "Not a valid input" << endl;
        return;
    }
    this->min = min;
    this->max = max;
    // Also will refill and shuffle vect
    fillVect();
}

void Random::fillVect()
{   
    double r;
    for (int i = 0; i < 250; i++)
    {
        r = (((double) rand() / (double) RAND_MAX) * (this->max - this->min)) + this->min ;
        numberList[i] = r;
        //if (i % 10 == 0)
            //cout << "Random number generated at index " << i << endl;
        // Shuffle at 90% 
        if (i == 250 * .9)
            shuffle();
    }
}

void Random::shuffle()
{
    double tmpFirst, tmpSecond, firstKey, secondKey;
    for (int i = 0; i < 100; i++)
    {
        // Get the random index, make sure they are not the same
        while (firstKey == secondKey) {
            firstKey = (((double) rand() / (double) RAND_MAX)) * 250;
            secondKey = (((double) rand() / (double) RAND_MAX)) * 250;
        }

        // Get the values from the index
        tmpFirst = numberList.at(firstKey);
        tmpSecond = numberList.at(secondKey);

        // Swap
        numberList[firstKey] = tmpSecond;
        numberList[secondKey] = tmpFirst;
    }
}

void Random::printVect()
{
    // 25 rows of 10 random numbers each
    for (int i = 0; i < 25; i++)
    {
        for (int j = 0; j < 10; j++)
            cout << (i * 10)+(j + 1) << ": " << numberList[(i * 10)+(j)] << "\t";
        cout << "\t" << endl;
    }
}

/*
Random::rInstance = NULL;

static Random *Random::rInstance()
{
    if (rInstance == NULL)
        rInstance = new Random;

    return rInstance;
}
*/