#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int tc;
    cin >> tc;

    while(tc--)
    {
        long long n, s, t, time = 0;
        cin >> n >> s >> t;
        
        while(n)
        {
            if(n % 2)
            {
                n--;
                time += s;
            }
            else
            {
                n /= 2;

                long long temp = n*s;
                if(temp < 0)
                {
                    time += t;
                }
                else
                {
                    time += min(t, n*s);
                }
            }
        }

        cout << time << "\n";
    }
}