#include <iostream>

using namespace std;

int main()
{
    int n;
    int k;

    cin >> n >> k;

    n--;
    k--;
    
    long long answer = 1;

    if(n-k < k)
    {
       k = n-k;
    }

    for(int i = 0; i < k; i++)
    {
       answer = answer * n--;
       answer = answer / (i+1);
    }
    cout << answer;
}