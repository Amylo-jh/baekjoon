#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector <int> house;
    int house_num;

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> house_num;

    for(int i = 0; i < house_num; i++)
    {
        int temp;
        cin >> temp;
        house.push_back(temp);
    }

    sort(house.begin(), house.end());

    cout << house[(house_num-1) / 2];
}