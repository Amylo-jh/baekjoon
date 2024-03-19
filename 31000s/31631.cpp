#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector <int> v = {0, 1, 2};
    vector <int> result = {0};

    for(int i = 3; i <= n; i++)
    {
        for(int j = 1; j < i; j++)
        {
            if(i % 4 == 0 && j == i/2+1)
            {
                result.push_back(1);
            }
            if(i % 4 == 1 && j == (i-1)/2+1)
            {
                result.push_back(1);
            }
            if(i % 4 == 2 && j == (i-1)/2+1)
            {
                result.push_back(1);
            }
            if(i % 4 == 3 && j == (i-1)/2+1)
            {
                result.push_back(1);
            }
            result.push_back(v[j] + 1);
        }
        v = result;
        result = {0};
    }

    for(int i = 1; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
}