#include <iostream>

using namespace std;

int main()
{
    int n, k, score, count = 0;
    cin >> n >> k >> score;
    for(int i = 1; i < n; i++)
    {
        int temp;
        cin >> temp;
        if(score - temp >= k)
        {
            count++;
        }
        score = temp;
    }
    cout << count;
}