#include <iostream>

using namespace std;

int main()
{
    int onehand;
    int nolook;
    int phonecoding;

    int score;
    int max_score = 0;

    int team;

    int a, b, c;

    cin >> onehand >> nolook >> phonecoding;
    cin >> team;

    for (int i = 0; i < team; i++)
    {
        score = 0;
        for(int j = 0; j < 3; j++)
        {
            cin >> a >> b >> c;
            score = score + a * onehand + b * nolook + c * phonecoding;
        }

        if(max_score < score)
        {
            max_score = score;
        }
    }

    cout << max_score;
}