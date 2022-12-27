#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void sol()
{
    int n;
    cin >> n;
    vector <int> person(n+1);
    vector <int> grouped(n+1);
    //grouped :
    //  0 = not group
    //  1 = start_pos
    //  2 = pending_grouping
    //  3 = grouped
    //  4 = cannot be grouped

    for(int i = 1; i <= n; i++)
    {
        int temp;
        cin >> temp;
        person[i] = temp;
    }

    for(int i = 1; i <= n; i++)
    {
        if(grouped[i] == 3)
        {
            continue;
        }

        queue <int> route;
        route.push(i);
        
        int next_person = person[i];
        grouped[i] = 1;
        
        while(1)
        {
            if(next_person < i)
            {
                while(!route.empty())
                {
                    int target_person = route.front();
                    grouped[target_person] = 4;
                    route.pop();
                }
                break;
            }

            if(grouped[next_person] == 1)
            {
                while(!route.empty())
                {
                    int target_person = route.front();
                    grouped[target_person] = 3;
                    route.pop();
                }
                break;
            }
            else if(grouped[next_person] == 3 || grouped[next_person] == 4)
            {
                while(!route.empty())
                {
                    int target_person = route.front();
                    grouped[target_person] = 4;
                    route.pop();
                }
                break;
            }
            else if(grouped[next_person] == 2)
            {
                int target_person = next_person;
                while(route.front() != target_person)
                {
                    grouped[route.front()] = 4;
                    route.pop();
                }
                while(!route.empty())
                {
                    target_person = route.front();
                    grouped[target_person] = 3;
                    route.pop();
                }
                break;
            }
            else if(grouped[next_person] == 0)
            {
                route.push(next_person);
                grouped[next_person] = 2;
                next_person = person[next_person];
            }
        }
    }

    int counter = 0;
    for(int i = 1; i <= n; i++)
    {
        if(grouped[i] != 3)
        {
            counter++;
        }
    }

    cout << counter << "\n";
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int tc;
    cin >> tc;

    while(tc--)
    {
        sol();
    }
}