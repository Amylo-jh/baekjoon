#include <iostream>
#include <vector>

#define min(a, b) (((a) < (b)) ? (a) : (b))
#define max(a, b) (((a) < (b)) ? (b) : (a))

using namespace std;

int main()
{
    int num[1000001]= {0, 0};
    
    int n;
    cin >> n;

    for(int i = 2; i <= n; i++)
    {
        num[i] = num[i-1] + 1;
        
        if(i % 3 == 0)
        {
            num[i] = min(num[i / 3] + 1, num[i]);
        }
        if(i % 2 == 0)
        {
            num[i] = min(num[i / 2] + 1, num[i]);
        }
    }

    cout << num[n];
}