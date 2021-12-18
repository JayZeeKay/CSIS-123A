/*
ID: 0602306

Jacob Marinas

12 December 2021

Lab Assignment 15 - Using the STL

Creating a priority queue
*/

#include <iostream>
#include <string>
#include <set>

#include "priQueue.h"

using namespace std;

int main()
{
	priQueue<string> queue;

    queue.enqueue("Jacob", 7);
    queue.enqueue("My", 1);
    queue.enqueue("Is", 4);
    queue.enqueue("Marinas", 9);
    queue.enqueue("Name", 2);

    cout << "Size: " << queue.size() << endl;
    cout << "Peeking: " << queue.peek() << endl;

    queue.dequeue();

    cout << "Size: " << queue.size() << endl;
    cout << "Peeking: " << queue.peek() << endl;

    queue.dequeue();

    cout << "Size: " << queue.size() << endl;
    cout << "Peeking: " << queue.peek() << endl;

    queue.dequeue();

    cout << "Size: " << queue.size() << endl;
    cout << "Peeking: " << queue.peek() << endl;

    queue.dequeue();

    cout << "Size: " << queue.size() << endl;
    cout << "Peeking: " << queue.peek() << endl;

	return 0;
}