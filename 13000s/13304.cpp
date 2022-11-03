#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;

    // 1~2 | 3~4여 | 3~4남 | 5~6여 | 5~6남
    vector <int> people(5);
    for(int i = 0; i < n; i++)
    {
        int s, y;
        cin >> s >> y;
        if(y == 1 || y == 2)
        {
            people[0]++;
        }
        else if(y == 3 || y == 4)
        {
            if(s)
            {
                people[2]++;
            }
            else
            {
                people[1]++;
            }
        }
        else if(y == 5 || y == 6)
        {
            if(s)
            {
                people[4]++;
            }
            else
            {
                people[3]++;
            }
        }
    }

    int room = 0;
    for(int i = 0; i < 5; i++)
    {
        room += people[i] / k;
        if(people[i] % k != 0)
        {
            room++;
        }
    }

    cout << room;
}