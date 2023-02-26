//https://www.acmicpc.net/contest/problem/829/1

#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n;
    cin >> n;
    n = n-4;
    n /= 4;

    for(int i = 0; i < n; i++)
    {
        cout << "long ";
    }

    cout << "long int";
}