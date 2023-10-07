#include <iostream>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    int total_people = 0;
    for(int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        total_people += temp;
    }

    if(total_people % m)
    {
        cout << 0;
    }
    else
    {
        cout << 1;
    }
}