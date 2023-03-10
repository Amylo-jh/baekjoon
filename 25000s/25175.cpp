#include <iostream>
#include <queue>

using namespace std;

int main()
{
    int n;
    int m;
    int k;

    cin >> n >> m >> k;
    
    int distance = k - 3;
    int jump = (m + distance) % n;

    if(jump <= 0)
    {
        jump = jump + n;
    }

    cout << jump;
}