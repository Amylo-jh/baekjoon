#include <iostream>

using namespace std;

int main()
{
    bool remainder[42] = {0};

    for(int i = 0; i < 10; i++)
    {
        int a;
        cin >> a;

        remainder[a % 42] = true;
    }

    int total = 0;

    for(int i = 0; i < 42; i++)
    {
        if(remainder[i])
        {
            total++;
        }
    }

    cout << total;
}