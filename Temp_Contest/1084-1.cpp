#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector <string> subject = {"swimming", "bowling", "soccer"};
    vector <int> arr(n);
    
    for(int i = 0; i < n; i++)
    {
        cout << subject[i%3] << " ";    
    }
    for(int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        if(str == "swimming")
        {
            if(i%3 == 1)
            {
                cout << "soccer ";
            }
            else
            {
                cout << "bowling ";
            }
        }
        else if(str == "bowling")
        {
            if(i%3 == 0)
            {
                cout << "soccer ";
            }
            else
            {
                cout << "swimming ";
            }
        }
        else
        {
            if(i%3 == 0)
            {
                cout << "bowling ";
            }
            else
            {
                cout << "swimming ";
            }
        }
    }
}