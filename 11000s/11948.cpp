#include <iostream>

using namespace std;

int main()
{
    int sub1[4];
    int sub2[2];

    int min_score = 100;
    int sum = 0;

    for(int i = 0; i < 4; i++)
    {
        int temp;
        cin >> temp;
        min_score = min(min_score, temp);
        sum = sum + temp;
    }
    sum -= min_score;

    min_score = 100;
    for(int i = 0; i < 2; i++)
    {
        int temp;
        cin >> temp;
        min_score = min(min_score, temp);
        sum = sum + temp;
    }
    sum -= min_score;

    cout << sum;
}