#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin >> n;

    for(int i = 0; i < n; i++)
    {
        int temp;
        int temp_neg;
        cin >> temp;
        temp_neg = temp * -1;
        int and_temp = temp & temp_neg;

        if(and_temp == temp)
        {
            cout << 1 << "\n";
        }
        else
        {
            cout << 0 << "\n";
        }
    }
}