#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n, m;
    string pass;
    cin >> n >> m;
    cin >> pass;

    for(int i = 0; i < m; i++)
    {
        string pass_candidate;
        cin >> pass_candidate;

        int index = 0;
        for(int i = 0; i < pass_candidate.length(); i++)
        {
            if(pass[index] == pass_candidate[i])
            {
                index++;
            }
        }

        if(index == n)
        {
            cout << "true" << endl;
        }
        else
        {
            cout << "false" << endl;
        }
    }
}