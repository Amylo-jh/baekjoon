#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, tmp;
    cin >> n;
    vector <int> arr(51);
    vector <int> answer;
    for(int i = 0; i < n*50; i++)
    {
        cin >> tmp;
        arr[tmp]++;
    }
    for(int i = 1; i <= 50; i++)
    {
        if(arr[i] > 2*n)
        {
            answer.push_back(i);
        }
    }
    if(answer.size() == 0)
    {
        cout << -1;
        return 0;
    }
    for(auto i : answer)
    {
        cout << i << " ";
    }
}