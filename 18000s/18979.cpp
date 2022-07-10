#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;



int main()
{
    int tc;
    cin >> tc;

    for(int q = 0; q < tc; q++)
    {
        vector <vector <int>> dots;
        int n;
        cin >> n;

        for(int i = 1; i <= 3*n; i++)
        {
            vector <int> temp;
            int x, y;
            cin >> x >> y;
            temp.push_back(x);
            temp.push_back(y);
            temp.push_back(i);
            dots.push_back(temp);
        }

        sort(dots.begin(), dots.end());

        for(int i = 0; i < 3*n;)
        {
            for(int j = 0; j < 3; j++)
            {
                cout << dots[i][2] << " ";
                i++;
            }
            cout << "\n";
        }
    }
}