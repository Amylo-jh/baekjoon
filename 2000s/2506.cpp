#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int combo = 1;
    int sum = 0;
    for(int i = 0; i < n; i++)
    {
        int score = 0;
        cin >> score;
        if(score)
        {
            sum += combo;
            combo++;
        }
        else
        {
            combo = 1;
        }
    }

    cout << sum;
}