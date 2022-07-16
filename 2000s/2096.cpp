#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector <vector <int>> dp_max = {{0,0,0}, {0,0,0}};
    vector <vector <int>> dp_min = {{1000000, 1000000, 1000000}, {1000000, 1000000, 1000000}};

    int n;
    cin >> n;

    cin >> dp_max[0][0] >> dp_max[0][1] >> dp_max[0][2];
    dp_min[0] = dp_max[0];

    for(int i = 1; i < n; i++)
    {
        vector <int> temp_vec = {0,0,0};
        dp_max[1] = {0, 0, 0};
        dp_min[1] = {1000000, 1000000, 1000000};

        cin >> temp_vec[0] >> temp_vec[1] >> temp_vec[2];

        for(int j = 0; j < 3; j++)
        {
            for(int k = -1; k < 2; k++)
            {
                if(0 <= j + k && j + k <= 2)
                {
                    dp_max[1][j] = max(dp_max[1][j], temp_vec[j] + dp_max[0][j+k]);
                    dp_min[1][j] = min(dp_min[1][j], temp_vec[j] + dp_min[0][j+k]);
                }
            }
        }
        dp_max[0] = dp_max[1];
        dp_min[0] = dp_min[1];
    }   

    int max_value = max(dp_max[0][0], dp_max[0][1]);
    max_value = max(max_value, dp_max[0][2]);

    int min_value = min(dp_min[0][0], dp_min[0][1]);
    min_value = min(min_value, dp_min[0][2]);

    cout << max_value << " " << min_value;
}