#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int p, n;
    cin >> p >> n;

    vector <int> item(n);
    for(int i = 0; i < n; i++)
    {
        cin >> item[i];
    }
    sort(item.begin(), item.end());

    int index = 0;
    while(p < 200 && index < n)
    {
        p += item[index];
        index++;
    }

    cout << index;
}