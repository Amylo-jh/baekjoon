#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    vector <vector <int>> student(6);
    for(int i = 0; i < 6; i++)
    {
        student[i].resize(2);
    }

    for(int i = 0; i < n; i++)
    {
        int g, s;
        cin >> s >> g;
        student[g-1][s]++;
    }

    int result = 0;
    for(int i = 0; i < 6; i++)
    {
        result += student[i][0] / k;
        if(student[i][0] % k)
        {
            result++;
        }
        result += student[i][1] / k;
        if(student[i][1] % k)
        {
            result++;
        }
    }

    cout << result;
}