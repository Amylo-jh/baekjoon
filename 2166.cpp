#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector <pair<long long, long long>> polygon;
    int dots;
    double area = 0;

    cin >> dots;

    for(int i = 0; i < dots; i++)
    {
        pair <long long, long long> dot; //x, y
        cin >> dot.first >> dot.second;
        polygon.push_back(dot);
    }

    polygon.push_back(polygon[0]);

    long long first_sum = 0;
    long long second_sum = 0;

    for(int i = 0; i < dots; i++)
    {
        first_sum += polygon[i].first * polygon[i+1].second;
        second_sum += polygon[i].second * polygon[i+1].first;
    }

    area = first_sum - second_sum;

    if(area < 0)
    {
        area = area * -1;
    }

    area /= 2;

    cout << fixed;
    cout.precision(1);
    cout << area;
}