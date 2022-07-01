#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int mirror = 0;

    vector <string> image;
    for(int i = 0; i < n; i++)
    {
        string temp;
        cin >> temp;
        image.push_back(temp);
    }

    cin >> mirror;

    if(mirror == 1)
    {
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                cout << image[i][j];
            }
            cout << endl;
        }
    }
    else if(mirror == 2)
    {
        for(int i = 0; i < n; i++)
        {
            for(int j = n-1; j >= 0; j--)
            {
                cout << image[i][j];
            }
            cout << endl;
        }
    }
    else if(mirror == 3)
    {
        for(int i = n-1; i >= 0; i--)
        {
            for(int j = 0; j < n; j++)
            {
                cout << image[i][j];
            }
            cout << endl;
        }
    }
}