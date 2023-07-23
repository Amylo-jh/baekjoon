#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int time = 0;
    cin >> time;
    for(int i = 1; i < n; i++)
    {
        time += 8;
        int temp;
        cin >> temp;
        time += temp;
    }

    cout << time/24 << " " << time%24;
}