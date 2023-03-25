#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    vector <int> ball(n+1);
    for(int i = 0 ; i < m; i++)
    {
        int start, end, num;
        cin >> start >> end >> num;

        for(int j = start; j <= end; j++)
        {
            ball[j] = num;
        }
    }

    for(int i = 1; i <= n; i++)
    {
        cout << ball[i] << " ";
    }
}