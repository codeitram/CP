// intersting note -ve no right shift will end in -1 because of ASL happens
#include <bits/stdc++.h>
using namespace std;

void updateIthBit(int &number, int index, int bitValue)
{
    // Method1:
    //     int setmask = 1 << index;
    //     int clearmask = ~setmask;
    //     bitValue == 0 ? (number = number & clearmask) : (number = number | setmask);

    // Method2: idea is if we OR with 0 and bitValue, bitValue would be set
    int mask = ~(1 << index);
    number = number & mask; // clears index bit
    bitValue = bitValue << index;
    number = number | bitValue;
}
void clearBitsInRange(int &number, int i, int j)
{
    int x = -1 << j + 1;
    int y = 1 << i - 1;
    int mask = x | y;
    number = number & mask;
}
int main(int argc, char const *argv[])
{
    // 1. Check if a number is odd or even
    int x = 23;
    cout << (23 & 1 ? "odd" : "even") << endl;

    // 2. get iTh bit of a number, coutning LSB as 0th bit
    int i = 1 << 2; // getting 3rd bit from LSB
    cout << ((x & i) == 0 ? 0 : 1);

    // 3. clear ith bit
    int j = 1 << 2;
    i = ~i;
    x = (x & i);
    cout << x;

    // 4. set ith bit
    int k = 1 << 2;
    x = 10;
    x = x | k;
    cout << "value of x is: " << x << endl;

    x = 10;
    updateIthBit(x, 1, 0);
    cout << x;

    return 0;
}
