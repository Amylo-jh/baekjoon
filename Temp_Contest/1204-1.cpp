#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int count = 0;
        cin >> count;
        while(count >= 5)
        {
            cout << "++++ ";
            count -= 5;
        }
        for(int j = 0; j < count; j++)
        {
            cout << "|";
        }
        cout << "\n"; 
    }
}