#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector <string> arr = {"PROBRAIN", "GROW", "ARGOS", "ADMIN", "ANT", "MOTION", "SPG", "COMON", "ALMIGHTY"};
    int solves = 0, idx = 0;
    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < n; j++)
        {
            int tmp;
            cin >> tmp;
            if(solves < tmp)
            {
                solves = tmp;
                idx = i;
            }
        }
    }

    cout << arr[idx];
}