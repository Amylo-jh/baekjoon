#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector <bool> record(200001);

    int n;
    cin >> n;

    int counter = 0;
    for(int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;

        if(record[a] == b)
        {
            counter++;
        }

        record[a] = b;
    }

    for(int i = 0; i < 200001; i++)
    {
        if(record[i])
        {
            counter++;
        }
    }

    cout << counter;
}