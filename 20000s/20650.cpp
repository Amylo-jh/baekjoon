#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector <long long> arr;
vector <bool> visited(7, false);

void check(long long num)
{
    for(int i = 0; i < 7; i++)
    {
        if(arr[i] == num && !visited[i])
        {
            visited[i] = true;
            return;
        }
    }
}

bool verify(long long a, long long b, long long c)
{
    visited = vector <bool> (7, false);

    check(a);
    check(b);
    check(c);
    check(a + b);
    check(a + c);
    check(b + c);
    check(a + b + c);

    for(int i = 0; i < 7; i++)
    {
        if(!visited[i])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    arr.resize(7);
    for(int i = 0; i < 7; i++)
    {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());

    long long a, b, c;
    for(int i = 0; i < 5; i++)
    {
        a = arr[i];
        for(int j = i + 1; j < 6; j++)
        {
            b = arr[j];
            for(int k = j + 1; k < 7; k++)
            {
                c = arr[k];

                if(verify(a, b, c))
                {
                    cout << a << " " << b << " " << c;
                    return 0;
                }
            }
        }
    }
}