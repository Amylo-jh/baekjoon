#include <iostream>
#include <string>

using namespace std;

int main()
{
    while(1)
    {
        string str;
        int age, weight;
        cin >> str >> age >> weight;
        if(str == "#")
        {
            break;
        }
        cout << str << " ";
        if(age > 17 || weight >= 80)
        {
            cout << "Senior\n";
        }
        else
        {
            cout << "Junior\n";
        }
    }
}