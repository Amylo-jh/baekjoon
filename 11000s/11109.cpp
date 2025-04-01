#include <iostream>

using namespace std;

int main()
{
    int tc;
    cin >> tc;

    while(tc--)
    {
        int d, n, s, p;
        cin >> d >> n >> s >> p;
        
        int parallel_time = d + n*p;
        int sequential_time = n*s;
        if(parallel_time < sequential_time)
        {
            cout << "parallelize\n";
        }
        else if(parallel_time > sequential_time)
        {
            cout << "do not parallelize\n";
        }
        else
        {
            cout << "does not matter\n";
        }
    }
}