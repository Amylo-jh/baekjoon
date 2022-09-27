#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector <int> content(n);
    int content_sum = 0;
    
    for(int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        content_sum += temp;
        content[i] = temp;
    }

    cout << content_sum << "\n";

    for(int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        if(temp)
        {
            content_sum -= content[i];
        }
    }

    cout << content_sum;
}