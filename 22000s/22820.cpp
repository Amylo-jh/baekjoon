#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int tc;
    cin >> tc;
    while(tc--)
    {
        vector <vector <int>> arr(5, vector <int>(5));
        for(int i = 0; i < 5; i++)
        {
            for(int j = 0; j < 5; j++)
            {
                cin >> arr[i][j];
            }
        }

        int max_size = 0;
        for(int x = 1; x <= 5; x++)
        {
            for(int y = 1; y <= 5; y++)
            {
                for(int i = 0; i+x <= 5; i++)
                {
                    for(int j = 0; j+y <= 5; j++)
                    {
                        bool flag = true;
                        for(int ii = i; ii < i+x; ii++)
                        {
                            for(int jj = j; jj < j+y; jj++)
                            {
                                if(!arr[ii][jj])
                                {
                                    flag = false;
                                    ii = jj = 5;
                                }
                            }
                        }
                        if(flag)
                        {
                            max_size = max(max_size, x*y);
                        }
                    }
                }
            }
        }
        cout << max_size << "\n";
    }
}