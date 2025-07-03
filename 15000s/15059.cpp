#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int answer = 0;
    vector <int> arr(3);
    for(int i = 0; i < 3; i++)
    {
        cin >> arr[i];
    }
    for(int i = 0; i < 3; i++)
    {
        int temp;
        cin >> temp;
        answer += max(0, temp - arr[i]);
    }
    cout << answer;
}