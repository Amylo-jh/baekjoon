#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector <int> seat(101);

    for(int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        seat[temp]++;
    }

    int counter = 0;
    for(int i = 1; i <= 100; i++)
    {
        if(seat[i])
        {
            counter += seat[i] - 1;
        }
    }

    cout << counter;
}