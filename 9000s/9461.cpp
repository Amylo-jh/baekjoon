#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector <long long> side_length = {1,1,1,2,2};

    for(int i = 5; i <= 100; i++)
    {
        long long temp = side_length[i-5] + side_length[i-1];
        side_length.push_back(temp);
    }

    int tc;
    cin >> tc;

    for(int i = 0; i < tc; i++)
    {
        int input;
        cin >> input;

        cout << side_length[input-1] << endl;
    }
}