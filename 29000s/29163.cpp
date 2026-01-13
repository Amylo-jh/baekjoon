#include <iostream>

using namespace std;

int main()
{
    int n, answer = 0;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        if(tmp % 2)
        {
            answer--;
        }
        else
        {
            answer++;
        }
    }
    if(answer > 0)
    {
        cout << "Happy";
    }
    else
    {
        cout << "Sad";
    }
}