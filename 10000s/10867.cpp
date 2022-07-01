#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    vector <int> array;
    int n;
    int temp;

    cin >> n;

    for(int i = 0; i < n; i++)
    {
        cin >> temp;
        array.push_back(temp);
    }

    sort(array.begin(),array.end());

    temp = 0;
    for(int i = 0; i < n; i++)
    {
        if(temp == array[i])
        {
            continue;
        }
        cout << array[i] << " ";
        temp = array[i];
    }
}