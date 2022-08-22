#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector <int> route(n);
    
    int city = -1;
    for(int i = 0; i < n; i++)
    {
        cin >> route[i];
        if(route[i] > city)
        {
            city = max(city, route[i]);
        }      
    }
    city++;
    cout << city << endl;

    vector <int> cities(city);
    vector <bool> visited(city);
    int root_city = 0;
    for(int i = 0; i < n; i++)
    {
        if(i == 0)
        {
            root_city = route[i];
            cities[route[i]] = -1;
            visited[route[i]] = true;
            continue;
        }
        if(visited[route[i]] == false)
        {
            visited[route[i]] = true;
            cities[route[i]] = route[i-1];
        }
    }

    for(int i = 0; i < city; i++)
    {
        cout << cities[i] << " ";
    }
}