#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int plug = 0;
    for(int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        plug += temp;
    }
    plug -= n-1;

    cout << plug;
}