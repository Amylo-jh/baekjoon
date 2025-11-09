#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector <pair <int, int>> arr(8);
    vector <int> answer;
    int sum = 0;
    for(int i = 0; i < 8; i++)
    {
        cin >> arr[i].first;
        arr[i].second = i+1;
    }
    sort(arr.begin(), arr.end(), greater<>());
    for(int i = 0; i < 5; i++)
    {
        if(arr[i].first)
        {
            sum += arr[i].first;
            answer.push_back(arr[i].second);
        }
    }
    sort(answer.begin(), answer.end());

    cout << sum << "\n";
    for(int i : answer)
    {
        cout << i << " ";
    }
}