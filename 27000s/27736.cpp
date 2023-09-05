#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int vote[3] = {0,0,0};
    
    for(int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        vote[temp+1]++;
    }

    if(vote[1] >= (n+1)/2)
    {
        cout << "INVALID";
    }
    else if(vote[0] >= vote[2])
    {
        cout << "REJECTED";
    }
    else
    {
        cout << "APPROVED";
    }
}