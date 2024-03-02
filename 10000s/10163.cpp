#include <iostream>
#include <vector>

using namespace std;

int arr[1001][1001];

int main()
{
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        int s1, s2, x, y;
        cin >> s1 >> s2 >> x >> y;
        for(int j = s1; j < s1+x; j++)
        {
            for(int k = s2; k < s2+y; k++)
            {
                arr[j][k] = i;
            }
        }
    }

    vector <int> counting(101);
    for(int i = 0; i <= 1000; i++)
    {
        for(int j = 0; j <= 1000; j++)
        {
            counting[arr[i][j]]++;
        }
    }

    for(int i = 1; i <= n; i++)
    {
        cout << counting[i] << "\n";
    }
}