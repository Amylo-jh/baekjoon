#include <iostream>
#include <cmath>

using namespace std;

struct location
{
    int x;
    int y;
};

double Get_Distance(location p1, location p2)
{
    int x = p1.x - p2.x;
    int y = p1.y - p2.y;

    if(x < 0)
        x * -1;
    if(y < 0)
        y * -1;

    double distance = x * x + y * y;
    distance = sqrt(distance);

    return distance;
}

int main()
{
    location points[4];
    // 0 = cat
    // 1 = person1
    // 2 = person2;
    // 3 = person3;

    double distance[6] = {0};

    for(int i = 0; i < 4; i++)
    {
        cin >> points[i].x >> points[i].y;
    }

    distance[0] = Get_Distance(points[0], points[1]) + Get_Distance(points[1], points[2]) + Get_Distance(points[2], points[3]);
    distance[1] = Get_Distance(points[0], points[1]) + Get_Distance(points[1], points[3]) + Get_Distance(points[3], points[2]);
    distance[2] = Get_Distance(points[0], points[2]) + Get_Distance(points[2], points[1]) + Get_Distance(points[1], points[3]);
    distance[3] = Get_Distance(points[0], points[2]) + Get_Distance(points[2], points[3]) + Get_Distance(points[3], points[1]);
    distance[4] = Get_Distance(points[0], points[3]) + Get_Distance(points[3], points[1]) + Get_Distance(points[1], points[2]);
    distance[5] = Get_Distance(points[0], points[3]) + Get_Distance(points[3], points[2]) + Get_Distance(points[2], points[1]);

    double shortest_distance = distance[0];
    for(int i = 0; i < 6; i++)
    {
        if(distance[i] < shortest_distance)
        {
            shortest_distance = distance[i];
        }
    }

    cout << int(shortest_distance);

}