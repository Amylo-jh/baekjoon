#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int hit = 0;
    for(int i = 1; i <= n; i++)
    {
        int temp;
        cin >> temp;
        if(temp != i)
        {
            hit++;
        }
    }

    cout << hit;
}