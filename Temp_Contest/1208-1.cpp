#include <iostream>

using namespace std;

int main()
{
    int t;
    cin >> t;
    int n, time = 0;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        time += temp;
    }

    if(time >= t)
    {
        cout << "Padaeng_i Happy";
    }
    else
    {
        cout << "Padaeng_i Cry";
    }
}