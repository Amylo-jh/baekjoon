#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector <int> num;
    int n;
    cin >> n;
    
    for(int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        num.push_back(temp);
    }

    int targetnum = 0;
    int count = 0;
    cin >> targetnum;

    for(int i = 0; i < n; i++)
    {
        if(targetnum == num[i])
        {
            count++;
        }
    }

    cout << count;
    
}