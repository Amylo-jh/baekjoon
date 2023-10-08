#include <iostream>
#include <vector>

using namespace std;

int main()
{
    long long n;
    cin >> n;

    long long sum = 0;
    int count = 0;
    for(int i = 1; i < n; i++)
    {
        sum += i;
        count++;
        if(sum > n)
        {
            break;
        }
    }
    cout << count-1;
}