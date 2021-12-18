#ifndef HASHNAMES
#define HASHNAMES

#include <vector>
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>

using namespace std;

class HashNames
{
    private:
        vector<vector<string> > hashNames;
        int djbHash(string data, int tablesize);
        void initialize();
    public:
        HashNames(string file);

        void hash(string file);
        void printNames();
        void writeNames();
};

HashNames::HashNames(string file)
{
    initialize();
    hash(file);
}

void HashNames::initialize()
{ 
    std::vector<std::string> v(0);

    for (int i = 0; i < 53; i++)
    {
        hashNames.push_back(v);
    }
    //cout << "hashNames size: " << hashNames.size() << endl;   
}

int HashNames::djbHash(string data, int tablesize)
{
    int hashVal = 5381;
    for (int i = 0; i < data.length(); i++)
    {
        hashVal *= 33;
        hashVal += static_cast<int>(data[i]);
    }

    hashVal %= tablesize;
    return abs(hashVal);
}

void HashNames::hash(string file)
{
    ifstream infile(file);
    int hash;
    vector<string> hashRow;

    if (!infile)
    {
        cout << "Error opening the file for reading" << endl;
        exit(-1);
    }

    string input;

    while (infile >> input)
    {
        //cout << input << endl;
        hash = djbHash(input, 53);
        //cout << "hash: " << hash << endl;
        hashNames[hash].push_back(input);
    }

    infile.close();
}

void HashNames::printNames()
{
    vector<std::string> row;
    
    for (int i = 0; i < 53; i++)
    {
        row = hashNames[i];
        cout << i << ": "; 
        for (int j = 0; j < row.size() - 1; j++)
        {
            cout << row[j] << ", ";
        }
        cout << row[row.size() - 1] << endl;
    }
}

#endif