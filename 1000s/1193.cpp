#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int sum = 2;
    int up = 0, down = 0;
    for(int i = 1; i < n; i++)
    {
        n -= i;
        sum++;
        up++;
        down++;
    }
    if(sum % 2)
    {
        up = n;
        down = sum - n; 
    }
    else
    {
        up = sum - n;
        down = n;
    }

    cout << up << "/" << down;

}