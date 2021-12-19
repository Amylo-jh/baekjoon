#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    vector <int> students;
    int teams;

    cin >> teams;

    for(int temp, i = 0; i < teams*3; i++)
    {
        cin >> temp;
        students.push_back(temp);
    }

    sort(students.begin(),students.end());

    int energy = students[teams*2 -1] - students[teams];

    cout << energy;
}