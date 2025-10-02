#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector <int> scholarship(11);
    int n, sum = 0;
    for(int i = 0; i <= 10; i++)
    {
        cin >> scholarship[i];
    }
    cin >> n;
    
    for(int i = 0; i < n; i++)
    {
        int div, credit;
        double gpa;
        cin >> div >> gpa >> credit;
        if(gpa >= 2.0 && credit >= 17)
        {
            sum += scholarship[div];
        }
    }
    cout << sum;
}