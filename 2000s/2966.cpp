#include <iostream>
#include <string>

using namespace std;

int main()
{
    string a = "ABC";
    string b = "BABC";
    string c = "CCAABB";

    int n;
    cin >> n;

    string answer;
    cin >> answer;

    int score_a = 0;
    int score_b = 0;
    int score_c = 0;

    for(int i = 0; i < n; i++)
    {
        if(answer[i] == a[i%3])
        {
            score_a++;
        }
        if(answer[i] == b[i%4])
        {
            score_b++;
        }
        if(answer[i] == c[i%6])
        {
            score_c++;
        }
    }

    int max_score = max(max(score_b, score_c), score_a);

    cout << max_score << "\n";

    if(max_score == score_a)
    {
        cout << "Adrian\n";
    }
    if(max_score == score_b)
    {
        cout << "Bruno\n";
    }
    if(max_score == score_c)
    {
        cout << "Goran\n";
    }
}