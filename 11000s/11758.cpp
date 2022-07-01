#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector <pair <int, int>> dots;
    double area = 0;

    for(int i = 0; i < 3; i++)
    {
        pair <int, int> dot;
        cin >> dot.first >> dot.second;
        dots.push_back(dot);
    }
    dots.push_back(dots[0]);

    long long first_sum = 0;
    long long second_sum = 0;

    for(int i = 0; i < 3; i++)
    {
        first_sum += dots[i].first * dots[i+1].second;
        second_sum += dots[i].second * dots[i+1].first;
    }

    area = first_sum - second_sum;

    if(area > 0)
    {
        cout << 1;
    }
    else if(area <0)
    {
        cout << -1;
    }
    else
    {
        cout << 0;
    }

}