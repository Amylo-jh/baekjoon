#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int max_score = 0;
    for(int i = 0; i < n; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;

        int score = a * (b + c);
        if(a == (b+c))
        {
            score *= 2;
        }

        max_score = max(max_score, score);
    }

    cout << max_score;
}