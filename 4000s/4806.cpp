#include <iostream>
#include <string>

using namespace std;

int main()
{
    int counter = 0;
    string str;
    while(getline(cin, str))
    {
        counter++;
    }

    cout << counter;
}