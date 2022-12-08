#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector <int> team1(10);
    vector <int> team2(10);

    for(int i = 0; i < 10; i++)
    {
        cin >> team1[i];
    }
    
    for(int i = 0; i < 10; i++)
    {
        cin >> team2[i];
    }

    sort(team1.begin(), team1.end(), greater<>());
    sort(team2.begin(), team2.end(), greater<>());

    int sum1 = 0;
    int sum2 = 0;
    for(int i = 0; i < 3; i++)
    {
        sum1 += team1[i];
        sum2 += team2[i];
    }

    cout << sum1 << " " << sum2;
}