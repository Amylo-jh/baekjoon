#include <iostream>
#include <deque>

using namespace std;

int main()
{
    int n;
    cin >> n;

    deque <pair<int, int>> ballons;

    for(int i = 1; i <= n; i++)
    {
        int temp;
        cin >> temp;
        ballons.push_back({i, temp});
    }

    for(int i = 1; i <= n; i++)
    {
        int ballon = ballons.front().first;
        int num = ballons.front().second;
        cout << ballon << " ";
        ballons.pop_front();
        

        if(ballons.empty())
        {
            continue;
        }

        if(num > 0)
        {
            for(int j = 0; j < num-1; j++)
            {
                pair <int, int> temp_pair = ballons.front();
                ballons.pop_front();
                ballons.push_back(temp_pair);
            }
        }
        else
        {
            for(int j = num; j < 0; j++)
            {
                pair <int, int> temp_pair = ballons.back();
                ballons.pop_back();
                ballons.push_front(temp_pair);
            }
        }
    }
}