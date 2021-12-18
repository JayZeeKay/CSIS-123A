#ifndef PRIQUEUE
#define PRIQUEUE

#include <vector>
#include <set>
#include <iostream>

#include "priQueue.h"

using namespace std;

template <class T>
class Node
{
private:
	T Data;
	int pri;
public:
	Node(T s, int i) : Data(s), pri(i) {}
	bool operator < (const Node& n) const { return pri < n.pri; }
	
	string getData() { return this->Data; }
	int getId() { return this->pri; }

};

template <class T>
class priQueue
{
    private:
        multiset<Node<T> > items;

    public:
        priQueue();

        void enqueue(T data, int order);
        void dequeue();
        T peek();
        int size();
};

template <class T>
priQueue<T>::priQueue()
{

}

template <class T>
void priQueue<T>::enqueue(T data, int order)
{
    if (order > 10 || order < 0)
        order = 5;
    items.insert(Node<T>(data, order));
    //sort();
}

template <class T>
void priQueue<T>::dequeue()
{
    items.erase(items.begin());
}

template <class T>
T priQueue<T>::peek()
{
    Node<T> n = *items.begin();
    return n.getData();
}

template <class T>
int priQueue<T>::size()
{
    return this->items.size();
}

#endif