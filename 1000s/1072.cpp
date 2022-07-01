#include <iostream>

using namespace std;

int main()
{
    long long total_game;
    long long win_game;
    
    cin >> total_game >> win_game;

    int win_percent = win_game * 100 / total_game;

    if(win_percent >= 99)
    {
        cout << -1;
        return 0;
    }

    int more_game = -1;

    int low = 0;
    int high = total_game;
    while(low <= high)
    {
        int mid = (low + high) / 2;
        int temp_percent = (win_game + mid) * 100 / (total_game + mid);

        if(temp_percent <= win_percent)
        {
            low = mid + 1;
            more_game = mid + 1;
        }
        else
        {
            high = mid -1;
        }
    }

    cout << more_game;
}