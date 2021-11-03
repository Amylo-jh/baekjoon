#include <iostream>

using namespace std;

int main()
{
    int test = 0;
    int n, m;
    long long bridges;

    cin >> test;

    for (int i = 0; i < test; i++)
    {
        cin >> n >> m;
        bridges = 1;
        for(int j = 1; j <= n; j++)
        {
            bridges = bridges * m-- / j;
        }

        cout << bridges << endl;
    }
}