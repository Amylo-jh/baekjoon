#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    vector <int> num;
    int min = INT32_MAX;
    int max = INT32_MIN;

    cin >> n;
    
    int temp;
    for(int i = 0; i < n; i++)
    {
        cin >> temp;
        num.push_back(temp);
    }

    for(int j = 0; j < n; j++)
    {
        if(num[j] < min)
        {
            min = num[j];
        }

        if(num[j] > max)
        {
            max = num[j];
        }
    }

    cout << min << " " << max;
}