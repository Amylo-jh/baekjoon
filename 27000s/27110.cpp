#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int counter = 0;
    for(int i = 0; i < 3; i++)
    {
        int temp;
        cin >> temp;

        if(temp < n)
        {
            counter += temp;
        }
        else
        {
            counter += n;
        }
    }

    cout << counter;
}