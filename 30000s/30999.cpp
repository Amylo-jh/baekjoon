#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    int count = 0;
    for(int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        int c = 0;
        for(int j = 0; j < m; j++)
        {
            if(str[j] == 'O')
            {
                c++;
            }
        }

        if(c > m/2)
        {
            count++;
        }
    }

    cout << count << endl;
}