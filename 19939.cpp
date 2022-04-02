#include <iostream>

using namespace std;

int main()
{
    int balls;
    int baskets;

    cin >> balls >> baskets;

    int min_ball = 0;

    for(int i = 1; i <= baskets; i++)
    {
        min_ball = min_ball + i;
    }

    if(balls >= min_ball)
    {
        balls = balls - min_ball;

        if(balls % baskets)
        {
            cout << baskets;
        }
        else
        {
            cout << baskets - 1;
        }
    }
    else
    {
        cout << -1;
    }
}