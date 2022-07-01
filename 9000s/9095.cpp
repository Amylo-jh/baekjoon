#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector <long long> dp = {0, 1, 2, 4};

    for(int i = 4; i <= 11; i++)
    {
        int next = dp[i-1] + dp[i-2] + dp[i-3];
        dp.push_back(next);
    }

    int n;
    cin >> n;

    for(int i = 0; i < n; i++)
    {
        int query;
        cin >> query;
        cout << dp[query] << "\n";
    }
}

// 1 = 1
// 1

// 2 = 2
// 1 +  1
// 2 + 

// 3 = 4
// 1 +  1 + 1
// 1 +  2

// 2 +  1

// 3 + 

// 4 = 7
// 1 +  1 + 1 + 1
// 1 +  1 + 2
// 1 +  2 + 1
// 1 +  3

// 2 +  1 + 1
// 2 +  2

// 3 +  1


// 5 = 13
// 1 +  1 + 1 + 1 + 1
// 1 +  1 + 1 + 2
// 1 +  1 + 2 + 1
// 1 +  1 + 3
// 1 +  2 + 1 + 1
// 1 +  2 + 2
// 1 +  3 + 1

// 2 +  1 + 1 + 1
// 2 +  1 + 2
// 2 +  2 + 1
// 2 +  3

// 3 +  1 + 1
// 3 +  2