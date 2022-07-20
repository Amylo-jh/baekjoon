#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    vector <int> odd; // 홀수
    vector <int> even; //짝수

    for(int i = 1; i <= n; i++)
    {
        int temp;
        cin >> temp;

        if(i % 2)
        {
            odd.push_back(temp);
        }
        else
        {
            even.push_back(temp);
        }
    }

    sort(even.begin(), even.end());
    sort(odd.begin(), odd.end());

    bool flag = false;

    for(int i = 0; i < even.size(); i++)
    {
        if(! (odd[i] < even[i]) )
        {
            flag = true;
        }
    }

    for(int i = 0; i < (even.size() - ((n+1) % 2) ); i++) // n이 홀수면 그대로, 짝수면 짝수번째 개수에서 1 빼고
    {
        if(! (even[i] < odd[i+1]) )
        {
            flag = true;
        }
    }

    if(flag)
    {
        cout << "NO";
    }
    else
    {
        cout << "YES";
    }
}