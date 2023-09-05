#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int score_a = 0;
    int score_b = 0;

    for(int i = 0; i < n; i++)
    {
        char ch;
        cin >> ch;

        if(ch == 'D')
        {
            score_a++;
        }
        else
        {
            score_b++;
        }

        if(abs(score_a - score_b) >= 2)
        {
            break;
        }
    }

    cout << score_a << ":" << score_b;
}