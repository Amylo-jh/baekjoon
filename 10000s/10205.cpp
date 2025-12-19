#include <iostream>
#include <string>

using namespace std;

int main()
{
    int tc;
    cin >> tc;
    for(int i = 1; i <= tc; i++)
    {
        string str;
        int answer = 0;
        cin >> answer >> str;
        for(char ch : str)
        {
            if(ch == 'c')
            {
                answer++;
            }
            else
            {
                answer--;
            }
        }
        cout << "Data Set " << i << ":\n";
        cout << answer << "\n\n";
    }
}