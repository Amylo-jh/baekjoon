#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector <int> cows(11);
    cows.assign(11, 2);

    int cross = 0;
    for(int i = 0; i < n; i++)
    {
        int c, p;
        cin >> c >> p;

        if(cows[c] != p)
        {
            if(cows[c] != 2)
            {
                cross++;
            }
            cows[c] = p;
        }
    }

    cout << cross;
}