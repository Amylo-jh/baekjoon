#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector <long long> arr;
    while(1)
    {
        long long tmp;
        cin >> tmp;
        if(!tmp)
        {
            break;
        }
        arr.push_back(tmp);
    }
    sort(arr.begin(), arr.end());
    int n = arr.size();

    for(int i = 0; i < n-2; i++)
    {
        for(int j = i+1; j < n-1; j++)
        {
            for(int k = j+1; k < n; k++)
            {
                if(arr[k] < arr[i] + arr[j])
                {
                    cout << arr[i] << " " << arr[j] << " " << arr[k];
                    return 0;
                }
            }
        }
    }

    cout << "NIE";
}