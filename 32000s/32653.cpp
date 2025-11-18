#include <iostream>
#include <numeric>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long n, answer = 1, temp;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> temp;        
        temp *= 2;
        answer = lcm(temp, answer);
    }
    cout << answer;
}