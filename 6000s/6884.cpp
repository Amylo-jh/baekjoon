#include <iostream>
#include <vector>

using namespace std;

vector <bool> num(100000001);

void init()
{
    for(int i = 0; i <= 100000000; i++)
    {
        num[i] = true;
    }
    num[0] = false;
    num[1] = false;
    
    for(int i = 2; i <= 50000000; i++)
    {
        if(num[i])
        {
            int n = 2;
            while(i * n <= 100000000)
            {
                num[i * n] = false;
                n++;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    init();

    int tc;
    cin >> tc;
    
    for(int q = 0; q < tc; q++)
    {
        int n;
        cin >> n;

        vector <int> array(n+1);
        vector <int> array_sum(n+1);
        for(int i = 1; i <= n; i++)
        {
            cin >> array[i];
        }
        array[0] = 0;
        array_sum[0] = 0;
        array_sum[1] = array[1];

        for(int i = 2; i <= n; i++)
        {
            array_sum[i] = array_sum[i-1] + array[i];
        }

        int distance = 1;
        bool flag = false;

        while (distance < n && !flag)
        {
            distance++;
            for(int i = 0; i <= n-distance; i++)
            {
                int sum = array_sum[i + distance] - array_sum[i];
                if(sum <= 100000000 && num[sum])
                {
                    cout << "Shortest primed subsequence is length ";
                    cout << distance;
                    cout << ": ";
                    
                    for(int j = i+1; j < i+1 + distance; j++)
                    {
                        cout << array[j] << " ";
                    }
                    flag = true;
                    break;
                }
            }
        }
        
        if(!flag)
        {
            cout << "This sequence is anti-primed.";
        }

        cout << "\n";
    }
}