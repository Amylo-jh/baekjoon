#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    
    vector <int> blobs;

    for(int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        blobs.push_back(temp);
    }

    int max_nearblobs = 0;

    for(int i = 0; i < n-2; i++)
    {
        int leftblob = blobs[i];
        int rightblob = blobs[i+2];
        int currblob = blobs[i+1];

        int curr_maxblob = 0;

        if(leftblob < rightblob)
        {
            curr_maxblob = currblob + leftblob;
        }
        else
        {
            curr_maxblob = currblob + rightblob;
        }

        if(curr_maxblob > max_nearblobs)
        {
            max_nearblobs = curr_maxblob;
        }
    }

    if(blobs[0] > max_nearblobs)
    {
        max_nearblobs = blobs[0];
    }
    if(blobs[n-1] > max_nearblobs)
    {
        max_nearblobs = blobs[n-1];
    }

    cout << max_nearblobs;
}