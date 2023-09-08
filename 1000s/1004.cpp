#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int tc;
    cin >> tc;
    while(tc--)
    {
        pair <int, int> start;
        pair <int, int> end;
        cin >> start.first >> start.second >> end.first >> end.second;

        int planet;
        cin >> planet;

        int counter = 0;
        for(int i = 0; i < planet; i++)
        {
            pair <int, int> pos;
            int rad;
            cin >> pos.first >> pos.second >> rad;

            rad = rad*rad;
            int dist1 = abs(start.first - pos.first)*abs(start.first - pos.first) + abs(start.second - pos.second) * abs(start.second - pos.second);
            int dist2 = abs(end.first - pos.first)*abs(end.first - pos.first) + abs(end.second - pos.second)*abs(end.second - pos.second);

            if((dist1 < rad) ^ (dist2 < rad))
            {
                counter++;
            }
        }

        cout << counter << "\n";
    }
}