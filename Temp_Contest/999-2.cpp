#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <tuple>

using namespace std;

bool comp1(tuple <int, int, string> a, tuple <int, int, string> b)
{
    return get<1>(a) < get<1>(b);
}

bool comp2(tuple <int, int, string> a, tuple <int, int, string> b)
{
    return get<0>(a) > get<0>(b);
}

int main()
{
    vector <tuple<int, int, string>> arr(3);
    for(int i = 0; i < 3; i++)
    {
        int solve, year;
        string name;
        cin >> solve >> year >> name;
        tuple <int, int, string> temp_tuple = make_tuple(solve, year, name);
        arr[i] = temp_tuple;
    }

    sort(arr.begin(), arr.end(), comp1);
    for(int i = 0; i < 3; i++)
    {
        cout << get<1>(arr[i]) % 100;
    }

    cout << "\n";
    sort(arr.begin(), arr.end(), comp2);
    for(int i = 0; i < 3; i++)
    {
        cout << get<2>(arr[i])[0];
    }

}