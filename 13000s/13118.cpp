#include <iostream>

using namespace std;

int main()
{
    int people[4];
    int apple;
    int person = 0;

    for(int i = 0; i < 4; i++)
    {
        cin >> people[i];
    }
    
    cin >> apple;

    for(int i = 0; i < 4; i++)
    {
        if(apple == people[i])
        {
            person = i+1;
        }
    }

    cout << person;
}