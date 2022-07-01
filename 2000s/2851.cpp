#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
    int mushroom[10] = {0};
    int curr_score = 0;
    int priv_score = 0;

    int priv_diff = 0;
    int curr_diff = 0;
    bool flag = true;

    for(int i = 0; i < 10; i++)
    {
        cin >> mushroom[i];
    }

    for(int j = 0; j < 10; j++)
    {
        curr_score = curr_score + mushroom[j];
        if(curr_score < 100)
        {
            priv_score = curr_score;
        }
        if(curr_score == 100)
        {
            cout << 100;
            flag = false;
            break;
        }
        if(curr_score > 100)
        {
            priv_diff = abs(100 - priv_score);
            curr_diff = abs(100 - curr_score);

            if(curr_diff <= priv_diff)
            {
                cout << curr_score;
            }
            else
            {
                cout << priv_score;
            }
            flag = false;
            break;
        }
    }

    if(flag)
    {
        cout << curr_score;
    }
}