#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector <vector <int>> people;
    int k, n;
    cin >> n >> k;

    for(int i = 0; i < k; i++)
    {
        vector <int> temp_vec;
        int group;
        cin >> group;
        for(int j = 0; j < group; j++)
        {
            int temp;
            cin >> temp;
            temp_vec.push_back(temp);
        }
        sort(temp_vec.begin(), temp_vec.end());
        people.push_back(temp_vec);
    }

    for(int i = 0; i < k; i++)
    {
        for(int j = 0; j < people[i].size(); j++)
        {
            cout << people[i][j] + 1 + j << " ";
        }
        cout << "\n";
    }
}