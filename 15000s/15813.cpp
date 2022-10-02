#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n;
    string name;
    cin >> n >> name;

    int score = 0;
    for(int i = 0; i < n; i++)
    {
        score += name[i] - 'A' + 1;
    }

    cout << score;    
}