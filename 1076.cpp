#include <iostream>
#include <string>
#include <math.h>

using namespace std;

int value(string input, int weight)
{
    int value = 0;

    if(input == "black")
    {
        value = 0;
    }
    else if(input == "brown")
    {
        value = 1;
    }
        else if(input == "red")
    {
        value = 2;
    }
        else if(input == "orange")
    {
        value = 3;
    }
        else if(input == "yellow")
    {
        value = 4;
    }
        else if(input == "green")
    {
        value = 5;
    }
        else if(input == "blue")
    {
        value = 6;
    }
        else if(input == "violet")
    {
        value = 7;
    }
        else if(input == "grey")
    {
        value = 8;
    }
    else if(input == "white")
    {
        value = 9;
    }

    if(weight == 2)
    {
        value = pow(10, value);
    }

    return value;
}

int main()
{
    string resist[3];
    long long resist_value[3];
    long long result = 1;

    for(int i = 0; i < 3; i++)
    {
        cin >> resist[i];
        resist_value[i] = value(resist[i], i);
    }

    result = (resist_value[0]*10 + resist_value[1]) * resist_value[2];
    
    cout << result;
}