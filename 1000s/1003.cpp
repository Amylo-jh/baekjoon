#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector <pair <int, int>> fibonacci(41);
    fibonacci[0] = {1, 0};
    fibonacci[1] = {0, 1};
    for(int i = 2; i <= 40; i++)
    {
        fibonacci[i].first = fibonacci[i-1].first + fibonacci[i-2].first;
        fibonacci[i].second = fibonacci[i-1].second + fibonacci[i-2].second;
    }

    int tc;
    cin >> tc;
    while(tc--)
    {
        int n;
        cin >> n;
        cout << fibonacci[n].first << " " << fibonacci[n].second << "\n";
    }
}