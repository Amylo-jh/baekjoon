#include <iostream>

using namespace std;

int main()
{
    int sum = 1800;
    for(int i = 0; i < 4; i++)
    {
        int temp;
        cin >> temp;
        sum -= temp;
    }

    if(sum >= 300)
    {
        cout << "Yes";
    }
    else
    {
        cout << "No";
    }
}