#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int person_number[200][4] = {0};

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            cin >> person_number[i][j];
        }
    }

    for(int i = 0; i < 3; i++)
    {
        int table[101] = {0};

        for(int j = 0; j < n; j++)
        {
            table[person_number[j][i]]++;
        }

        for(int j = 0; j < n; j++)
        {
            if(table[person_number[j][i]] == 1)
            {
                person_number[j][3] += person_number[j][i];
            }
        }
    }

    for(int i = 0; i < n; i++)
    {
        cout << person_number[i][3] << endl;
    }
}