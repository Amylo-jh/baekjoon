#include <iostream>

using namespace std;

int main()
{
    int a, b, k, x;
    cin >> a >> b >> k >> x;

    int start, end;
    start = k - x;
    end = k + x;
    start = max(start, a);
    end = min(end, b);

    int counter = 0;
    for(int i = start; i <= end; i++)
    {
        counter++;
    }
    
    if(counter == 0)
    {
        cout << "IMPOSSIBLE";
    }
    else
    {
        cout << counter;
    }
}