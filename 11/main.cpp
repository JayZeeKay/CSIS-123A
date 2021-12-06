/*
ID: 0620306

Jacob Marinas

Lab Assignment 10 - Recursion

Writing the setValue and bitsToIn as recursive functions
*/

#include <iostream>

using namespace std;

int bitsToInt(int ar[]);
void setValue(int ar[], int value);
string toString(int ar[]);

int main()
{
    int byte[8] = {0, 0, 0, 0, 0, 0, 0, 0};
    int val;

    cout << "Enter a value to set the byte" << endl;
    cin >> val;

    setValue(byte, val);

    cout << "The byte in bits is: " << toString(byte) << endl;
    cout << "The byte in int is: " << bitsToInt(byte) << endl;

    return 0;
}


int bitsToInt(int ar[])
{
    static int bit = 7;
    static int mask = 128;
    static int sum = 0;
    if (bit == 0)
    {
        return sum + ar[bit];
    }
    else 
    {
        sum += ar[bit] * mask;
    }
    bit--;
    mask = mask >> 1;
    return bitsToInt(ar);
}


void setValue(int ar[], int value)
{
    // Start with the largest bit and mask
    static int bit = 7;
    static int mask = 128;
    //cout << "bit value: " << bit << endl;
    //cout << "value value: " << value << endl;
    if (bit == 0)
    {
        // Base case; first bit, value can only be 1 or 0 because of previous iterations of value subtracted by mask
        ar[bit] = value;
        return;
    }
    else if (value >= mask)
    {
        // At the current bit, set to 1 if the value is greater than the bit (a power of 2)
        ar[bit] = 1;
        value -= mask;
    } 
    else
    {
        // At the current bit, set to 0 otherwise
        ar[bit] = 0;
    }
    // Point to lower bit in the byte
    bit--;
    // Shift the mask one bit to the right (smaller by a power of 2)
    mask = mask >> 1;
    return setValue(ar, value);
}

string toString(int ar[])
{
    string byteString = "00000000";
    for (int i = 7; i >= 0; i--)
    {
        if (ar[i])
            byteString[7-i] = '1';
        else
            byteString[7-i] = '0';
    }
    return byteString;
}