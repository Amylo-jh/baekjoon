#include <iostream>

using namespace std;

int main()
{
    int testcases;
    int a, b;
    cin >> testcases;
    
    for(int i = 0; i < testcases; i++)
    {
        cin >> a >> b;

        int temp = a;
        for(int j = 1; j < b; j++)
        {
            temp = temp * a;
            temp = temp % 10;
        }
        temp = temp % 10;
        
        if(temp == 0)
        {
            cout << 10 << endl;
            continue;
        }
        cout << temp << endl;
    }
}