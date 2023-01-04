#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int score_a = 100;
    int score_b = 100;

    for(int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;

        if(a > b)
        {
            score_b -= a;
        }
        else if(a < b)
        {
            score_a -= b;
        }
    }

    cout << score_a << "\n" << score_b; 
}