#include <iostream>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    int helmet = 0;
    int vest = 0;

    for(int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        helmet = max(helmet, temp);
    }
    for(int i = 0; i < m; i++)
    {
        int temp;
        cin >> temp;
        vest = max(vest, temp);
    }

    cout << helmet + vest;
}