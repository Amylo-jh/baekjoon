#include <iostream>

using namespace std;

int main()
{
    int max_score = 0;
    int index = 0;
    for(int i = 1; i <= 5; i++)
    {
        int score = 0;
        for(int j = 0; j < 4; j++)
        {
            int temp;
            cin >> temp;
            score += temp;
        }
        if(score > max_score)
        {
            max_score = score;
            index = i;
        }
    }

    cout << index << " " << max_score;
}