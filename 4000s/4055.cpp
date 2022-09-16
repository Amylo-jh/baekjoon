#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int day = 0;
    while(1)
    {
        day++;
        int n;
        vector <pair <int, int>> party;
        vector <bool> visited;
        cin >> n;
        if(n == 0)
        {
            break;
        }
        for(int i = 0; i < n; i++)
        {
            pair <int, int> temp_pair;
            cin >> temp_pair.first >> temp_pair.second;
            if(temp_pair.first == temp_pair.second)
            {
                continue;
            }
            party.push_back(temp_pair);
            visited.push_back(false);
        }
        sort(party.begin(), party.end());

        int counter = 0;
        int time2 = 16;
        while(time2 < 48)
        {
            int time = time2 / 2;
            int index = -1;
            int min_endtime = 48;
            for(int i = 0; i < party.size(); i++)
            {
                if(party[i].first <= time && time < party[i].second &&
                visited[i] == false)
                {
                    if(min_endtime > party[i].second)
                    {
                        min_endtime = party[i].second;
                        index = i;
                    }
                    
                }
            }

            if(index >= 0)
            {
                visited[index] = true;
                counter++;
            }

            time2++;
        }
        
        cout << "On day ";
        cout << day;
        cout << " Emma can attend as many as ";
        cout << counter;
        cout << " parties." << "\n";
    }
}