#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n, l;
    cin >> n >> l;

    vector <int> area(n);
    for(int i = 0; i < n; i++)
    {
        cin >> area[i];
    }
    sort(area.begin(), area.end());

    int start_point = area[0];
    int tape = 1;
    int index = 1;

    while(index < n)
    {
        if(start_point <= area[index] - l)
        {
            start_point = area[index];
            tape++;
        }
        index++;
    }

    cout << tape;
}