#include <iostream>
#include <string>

using namespace std;

int char_decision(char ch1)
{
    switch (ch1)
    {
    case 'A':
    case 'B':
    case 'C':
        return 2;
    case 'D':
    case 'E':
    case 'F':
        return 3;
    case 'G':
    case 'H':
    case 'I':
        return 4;
    case 'J':
    case 'K':
    case 'L':
        return 5;
    case 'M':
    case 'N':
    case 'O':
        return 6;
    case 'P':
    case 'Q':
    case 'R':
    case 'S':
        return 7;
    case 'T':
    case 'U':
    case 'V':
        return 8;
    case 'W':
    case 'X':
    case 'Y':
    case 'Z':
        return 9;
    }
}

int main()
{
    string str;
    int length;
    int time = 0;

    cin >> str;
    length = str.length();

    for(int i = 0; i < length; i++)
    {
        time = time + char_decision(str[i]);
    }

    time = time + length;

    cout << time;
}