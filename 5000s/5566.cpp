#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector <int> arr(n+1);
    for(int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }

    int count = 1;
    int pos = 1;
    for(int i = 0; i < m; i++)
    {
        int dice;
        cin >> dice;
        pos += dice + arr[pos+dice];

        if(pos >= n)
        {
            cout << count;
            break;
        }
        count++;
    }
}