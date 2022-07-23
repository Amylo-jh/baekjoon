#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main()
{
    vector <int> crain;
    vector <int> box;
    int c;
    int c_max = 0;
    int b;
    int b_max = 0;
    
    cin >> c;
    for(int i = 0; i < c; i++)
    {
        int temp;
        cin >> temp;
        c_max = max(c_max, temp);
        crain.push_back(temp);
    }
    sort(crain.begin(), crain.end(), greater<>());

    cin >> b;
    for(int i = 0; i < b; i++)
    {
        int temp;
        cin >> temp;
        b_max = max(b_max, temp);
        box.push_back(temp);
    }
    sort(box.begin(), box.end(), greater<>());

    if(c_max < b_max)
    {
        cout << -1;
        return 0;
    }

    int time = 0;
    
    while(!box.empty())
    {
        for(int i = 0; i < crain.size(); i++)
        {
            for(int j = 0; j < box.size(); j++)
            {
                if(!box.empty() && (crain[i] >= box[j]))
                {
                    box.erase(box.begin() + j);
                    break;
                }
            }
        }
        time++;
    }

    cout << time;
}