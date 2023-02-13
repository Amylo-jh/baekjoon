#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector <int> line(4);
    for(int i = 0; i < 4; i++)
    {
        cin >> line[i];
    }
    sort(line.begin(), line.end(), greater<>());
    cout << line[1] * line[3];
}