#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector <vector<long long>> pascal_triangle = {{1}, {1,1}};

    for(int i = 2; i < 30; i++)
    {
        vector <long long> temp_vec;
        for(int j = 0; j <= i; j++)
        {
            long long temp;
            if(j == 0 || j == i)
            {
                temp = 1;
                temp_vec.push_back(temp);
                continue;                
            }

            temp = pascal_triangle[i-1][j-1] + pascal_triangle[i-1][j];
            temp_vec.push_back(temp);            
        }
        pascal_triangle.push_back(temp_vec);
    }

    int r, c, w;
    cin >> r >> c >> w;

    long long total = 0;

    int j_limit = c;
    for(int i = r - 1; i < r + w - 1; i++)
    {
        for(int j = c -1; j < j_limit; j++)
        {
            total = total + pascal_triangle[i][j];
        }
        j_limit++;
    }

    cout << total;
}