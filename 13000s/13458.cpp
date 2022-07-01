#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector <int> classroom;
    int n;
    cin >> n;

    long long main_viewer;
    long long sub_viewer;
    long long total_viewer = 0;

    for(int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        classroom.push_back(temp);
    }

    cin >> main_viewer >> sub_viewer;

    for(int i = 0; i < n; i++)
    {
        classroom[i] = classroom[i] - main_viewer;
        total_viewer++;

        if(classroom[i] > 0)
        {
            total_viewer += (classroom[i] / sub_viewer) + bool(classroom[i] % sub_viewer);
        }
    }

    cout << total_viewer;
}