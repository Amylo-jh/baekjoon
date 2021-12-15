#include <iostream>

using namespace std;

int main()
{
    int score[5];
    int total = 0;

    for(int i = 0; i < 5; i++)
    {
        cin >> score[i];

        if(score[i] < 40)
        {
            score[i] = 40;
        }
        total = total + score[i];
    }

    cout << total/5;
}