#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector <int> odd;
    int sum = 0;
    for(int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;

        if(temp % 2 == 0)
        {
            sum += temp;
        }
        else
        {
            odd.push_back(temp);
        }
    }

    sort(odd.begin(), odd.end(), greater<>());

    int index = (odd.size() / 2) * 2;
    for(int i = 0; i < index; i++)
    {
        sum += odd[i];
    }

    cout << sum;
}